#[macro_use] extern crate rocket;
mod models;
use models::Post;
use rocket::serde::json::Json;
#[get("/")]
fn index() -> &'static str {
    "Hello, world!"
}
#[get("/random")]
fn get_random_blog_post() -> Json<Post>{
    return Json(Post { id: 2, title: "test".to_string(), edited: false });
}
#[launch]
fn rocket() -> _ {
    let rocket = rocket::build();
    rocket.mount("/", routes![index])
}