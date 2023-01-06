
use actix_web::{
    get, 
    post, 
    put,
    error::ResponseError,
    web::Path,
    web::Json,
    web::Data,
    HttpResponse,
    http::{header::ContentType, StatusCode}
};
use serde::{Serialize, Deserialize};
pub s

#[get("/task/{task_id}")]
pub async fn get_task() -> Json<String>{
    return Json("hello world".to_string());
}