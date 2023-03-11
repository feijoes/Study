mod rewrite;
use wasm_bindgen::prelude::*;
use web_sys::{Request, Response, Headers, ResponseInit};
use url::Url;
include!(concat!(env!("OUT_DIR"),"\\map.rs"));

#[wasm_bindgen]
pub async fn handler(request: Request) -> Result<Response, JsValue> {
    console_error_panic_hook::set_once();
  
    let url: Url = request.url().parse().unwrap();
    let mut init = ResponseInit::default();
    if let Some(( _, destination )) = MAPPINGS.iter().find(|( key, _ )| *key == url.path() ){
        let headers = Headers::new()?;
        headers.set( "Location", destination )?;
    
        
        init.headers(&headers).status(302);
        // entry.map(|(_, v)| *v)
        Response::new_with_opt_str_and_init(Some("Redirectin"),&init)
    }
    else{
        init.status(404);
        Response::new_with_opt_str_and_init(Some("Not found"),&init)
    }
    
    
}
