mod api;
use api::task::{get_task};
use actix_web::{HttpServer,App,web::Data,middleware::Logger};
use std::io::Result;
use std::env::set_var;

#[actix_web::main]
async fn main() -> Result<()> {
    set_var("RUST_LOG", "debug");
    set_var("RUST_BACKTRACE", "1");
    env_logger::init();

    HttpServer::new(move || {
  
        App::new().service(get_task)
    }).bind(("127.0.0.1",80))?.run().await


}
