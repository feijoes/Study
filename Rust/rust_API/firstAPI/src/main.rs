mod api;
mod repo;
mod model;
use api::task::{get_task};
use actix_web::{HttpServer,App,web::Data,middleware::Logger};
use std::io::Result;
use std::env::set_var;
use repo::ddb::DDBRepository;
#[actix_web::main]
async fn main() -> Result<()> {
    set_var("RUST_LOG", "debug");
    set_var("RUST_BACKTRACE", "1");
    env_logger::init();
    
    let config = aws_config::load_from_env().await;
    
    HttpServer::new(move || {
        let ddb_repo: DDBRepository = DDBRepository::init(
            "task".to_string(),
            config.clone()
        );
        let ddb_data: Data<DDBRepository> = Data::new(ddb_repo);
    
        App::new()
        .wrap(Logger::default())
        .app_data(ddb_data)
        .service(get_task)
    })
    .bind(("127.0.0.1",80))?
    .run()
    .await


}
