#[macro_use] extern crate rocket;
mod models;
mod db;
mod schema;
use db::establish_connection;
use models::{NewPost};
use rocket::serde::json::Json;
use diesel::RunQueryDsl;
#[get("/")]
fn index() -> &'static str {
    ""
}
#[get("/all")]
fn get_all_posts() -> Json<Vec<NewPost>> {
    return Json(vec![
        NewPost {
            id: 31,
            title: "Some title".to_string(),
            edited: false
        },
        NewPost {
            id: 3441,
            title: "Some 3q".to_string(),
            edited: true
        }
      ]
    )
}

#[post("/", data = "<blog_post>")]
async fn create_blog_post(blog_post: Json<NewPost>) -> Json<NewPost> {
    use crate::schema::posts::dsl::posts;
    let mut connection = establish_connection();
    diesel::insert_into(posts)
    .values(NewPost {id: 3,title: "d".to_string(),edited: false})
    .execute(&mut connection)
    .expect("Error saving new video");
    blog_post
}
pub struct Db(diesel::PgConnection);

#[launch]
fn rocket() -> _ {
    let rocket = rocket::build();
    rocket
        .mount("/", routes![index])
        .mount("/", routes![get_all_posts])
        .mount("/", routes![create_blog_post])
    }