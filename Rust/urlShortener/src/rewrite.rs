#[allow(dead_code)]

#[derive(Debug, Eq, PartialEq)]
pub enum Error {
    InvalidEntry(usize),
    DuplicateKey(String),
    InvalidUrl(String),
}
use url::Url;

#[allow(dead_code)]
pub fn parse(txt: &str) -> Result<Vec<(&str,Url)>,Error>{
    let mut mappings: Vec<(&str,Url)> = Vec::new();
  
    for ( nline, line) in txt.lines().enumerate(){
        if line.starts_with("#"){
            continue;
        }

        let (key,mut  value) = line.split_once(" ")
            .ok_or_else(|| Error::InvalidEntry(nline+1))?;

        if let Some(index) = value.find("#"){
            value = value[..index].trim()
        }
        let url: Url = value.parse().map_err(|err| Error::InvalidUrl(format!("'{value}' is not a valid URL: {err}")))?;
        mappings.push((key, url))
    }

    mappings.sort_by_key(|entry| entry.0);
    let mut prev = None;
    for (key,_) in &mappings {
        if Some(*key) == prev {
            return Err(Error::DuplicateKey(format!("duplicate key: {key}")));
        }
        prev = Some(key)
    }   
    Ok(mappings)
}
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_comment() {
        assert_eq!(parse("# Comment line").unwrap(), vec![]);
    }
    
    #[test]
    fn test_mapping() {
        assert_eq!(
            parse("test https://example.com/here").unwrap(),
            vec![("test","https://example.com/here".parse().unwrap())]
        );
    }
     
    #[test]
    fn test_mapping_with_comment() {
        assert_eq!(
            parse("test https://example.com/here # comment").unwrap(),
            vec![("test", "https://example.com/here".parse().unwrap())]
        );
    }
   
    #[test]
    fn test_invalid_url() {
        assert_eq!(
            parse("test invalid"),
            Err(Error::InvalidUrl(
                "'invalid' is not a valid URL: relative URL without a base".to_string()
            ))
        );
    }

    #[test]
    fn test_duplicate_entry() {
        assert_eq!(
            parse("test https://example.com/\ntest https://example.com/other"),
            Err(Error::DuplicateKey("duplicate key: test".to_string()))
        );
    }

    #[test]
    fn test_malformed_entry() {
        assert_eq!(parse("test"), Err(Error::InvalidEntry(1)));
    }

}