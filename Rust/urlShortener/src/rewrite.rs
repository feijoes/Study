use std::intrinsics::variant_count;

/* 
#[derive(Debug, Eq, PartialEq)]
pub enum Error {
    InvalidEntry(usize),
    DuplicateKey(String),
    InvalidUrl(String),
}
*/
pub fn parse(txt: &str) -> Option<Vec<(&str,&str)>>{
    let mut mappings = Vec::new();
  
    for line in txt.lines(){
        if line.starts_with("#"){
            continue;
        }
        let (key,mut  value) = line.split_once(" ")?;
        if let Some(index) = value.find("#"){
            value = value[..index].trim()
        }
         
        mappings.push((key, value))
    }
    Some(mappings)
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
            vec![("test","https://example.com/here")]
        );
    }
     
    #[test]
    fn test_mapping_with_comment() {
        assert_eq!(
            parse("test https://example.com/here # comment").unwrap(),
            vec![("test", "https://example.com/here")]
        );
    }
    /*
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
    */
}