
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
use strum_macros::{Display};

#[derive(Deserialize,Serialize)]
pub struct TaskIdentifier{
    task_id: String,
}
#[get("/task/{task_id}")]
pub async fn get_task(task_identifier: Path<TaskIdentifier>) -> Json<String>{
    return Json(task_identifier.into_inner().task_id);
}