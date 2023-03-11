mod rewrite;

use wasm_bindgen::prelude::*;
use web_sys::{Request, Response};
include!(concat!(env!("OUT_DIR"),"\\map.rs"));
#[wasm_bindgen]
pub async fn handler(request: Request) -> Result<Response, JsValue> {
    console_error_panic_hook::set_once();
  
    let _url: String = request.url();



    Response::new_with_opt_str(Some("Hello from Rust 🦀"))
}
