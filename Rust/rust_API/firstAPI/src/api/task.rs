
use actix_web::{
    get, 
    post, 
    put,
    error::ResponseError,
    web::Path,
    web::Json,
    web::Data,
    HttpResponse,
    http::{header::ContentType, StatusCode}, body
};
use serde::{Serialize, Deserialize};
use strum_macros::{Display};

#[derive(Deserialize,Serialize)]
pub struct TaskIdentifier{
    task_id: String,
}
#[derive(Deserialize,Serialize)]
pub struct TaskCompletionRequest{
    result_file: String,
}

#[derive(Deserialize)]
pub struct SubmitTaskRequest{
    user_id: String,
    task_typep: String,
    source_file: String
}

pub enum TaskError{
    TaskNotFound,
    TaskUpdateFailure,
    TaskCreationFailure,
    BadTaskRequest
}



#[get("/task/{task_id}")]
pub async fn get_task(task_identifier: Path<TaskIdentifier>, body: Json<Str>) -> Json<String>{
    return Json(task_identifier.into_inner().task_id);
}