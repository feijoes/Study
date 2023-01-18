#[macro_use] extern crate rocket;
mod models;
use models::Post;
use rocket::serde::json::Json;
#[get("/")]
fn index() -> &'static str {
    "Hello, world!"
}
#[get("/all")]
fn get_all_posts() -> Json<Vec<Post>> {
    return Json(vec![
        Post {
            id: 31,
            title: "Some title".to_string(),
            edited: false
        },
        Post {
            id: 3441,
            title: "Some 3q".to_string(),
            edited: true
        }
      ]
    )
}
#[post("/", data = "<blog_post>")]
fn create_blog_post(blog_post: Json<Post>) -> Json<Post> {
    blog_post
}
#[launch]
fn rocket() -> _ {
    let rocket = rocket::build();
    rocket
        .mount("/", routes![index])
        .mount("/", routes![get_all_posts])
        .mount("/", routes![create_blog_post])
    }