mod rewrite;
use wasm_bindgen::prelude::*;
use web_sys::{Request, Response, Headers, ResponseInit};
use url::Url;
include!(concat!(env!("OUT_DIR"),"\\map.rs"));

const HOME_PAGE: &str = include_str!("./home.html");

#[wasm_bindgen]
pub async fn handler(request: Request) -> Result<Response, JsValue> {
    console_error_panic_hook::set_once();
  
    let url: Url = request.url().parse().unwrap();
    let path = url.path();
    let mut init = ResponseInit::default();

    if path == "/" {
        return home(request).await;
    }

    match MAPPINGS.binary_search_by_key(&path,|e| e.0) {
        Ok(index) => {
            let ( _, destination ) = MAPPINGS[index];
            let headers = Headers::new()?;
            headers.set( "Location", destination )?;

    
            init.headers(&headers).status(302);
            // entry.map(|(_, v)| *v)
            Response::new_with_opt_str_and_init(Some("Redirectin"),&init)
        }
        _ => {
            init.status(404);
            Response::new_with_opt_str_and_init(Some("Not found"),&init)
        }
    }
    
    
}
pub async fn home(_request: Request) -> Result<Response, JsValue> {
    let mut init = ResponseInit::default();
    let headers = Headers::new()?;
    headers.set("Content-Type", "text/html")?;
    init.headers(&headers);

    Response::new_with_opt_str_and_init(Some(HOME_PAGE), &init)
}
