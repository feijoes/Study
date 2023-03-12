extern crate core;
#[path ="src/rewrite.rs"]
mod rewrite;
use rewrite::parse;
use url::Url;
use std::{path::Path, fs::{self, File}};
use std::{env, io};
use std::io::Write;
// use url::Url;
fn main() -> () {
    let path = Path::new(&env::var_os("OUT_DIR").unwrap()).join("map.rs");
    let maps = fs::read_to_string("mappings.txt")
        .expect("error reading mappings.txt");
    let mut mappings = parse(&maps).expect("error parsing");
    mappings.sort_by_key(|entry| entry.0);
    write_output(&path, &mappings).expect("error writing output file");
}
fn write_output(path: &Path, mappings: &[(&str, Url)]) -> Result<(), io::Error> {
    let mut f = File::create(&path).expect("unable to create output file");
    writeln!(f, "pub const MAPPINGS: &[(&str, &str)] = &[")?;

    for (key, val) in mappings.iter() {
        writeln!(f, r#"    ("{}", "{}"),"#, key, val)?;
    }

    writeln!(f, "];")
}