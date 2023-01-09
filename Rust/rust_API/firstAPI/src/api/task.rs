
use actix_web::{
    get, 
    post, 
    put,
    error::ResponseError,
    web::Path,
    web::Json,
    web::Data,
    HttpResponse,
    http::{header::ContentType, StatusCode}, body, cookie::Display
};
use serde::{Serialize, Deserialize};
use strum_macros::{Display};
use crate::model::task::Task;
use crate::model::task::TaskState;


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

#[derive(Debug,Display)]
pub enum TaskError{
    TaskNotFound,
    TaskUpdateFailure,
    TaskCreationFailure,
    BadTaskRequest
}

impl ResponseError for TaskError {
    fn error_response(&self) -> HttpResponse {
        HttpResponse::build(self.status_code())
            .insert_header(ContentType::json())
            .body(self.to_string())
    }
    

    fn status_code(&self) -> StatusCode {
        match self {
            TaskError::TaskNotFound => StatusCode::NOT_FOUND,
            TaskError::TaskUpdateFailure => StatusCode::FAILED_DEPENDENCY,
            TaskError::TaskCreationFailure => StatusCode::FAILED_DEPENDENCY,
            TaskError::BadTaskRequest => StatusCode::BAD_REQUEST
        }
    }
}

#[get("/task/{task_id}")]
pub async fn get_task(task_identifier: Path<TaskIdentifier>) -> Result<Json<Task>,TaskState>{
    return Json(task_identifier.into_inner().task_id);
}
