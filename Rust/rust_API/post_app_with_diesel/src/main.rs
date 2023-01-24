#[macro_use] extern crate rocket;
mod models;
mod db;
mod schema;


use db::establish_connection;
use models::{NewPost,Post};
use rocket::serde::json::Json;
use diesel::{RunQueryDsl, QueryDsl};
#[get("/")]
fn index() -> &'static str {
    ""
}
#[get("/all")]
async fn get_all_posts() -> Json<Vec<Post>> {
    use crate::schema::posts::dsl::*;

    let connection = &mut establish_connection();
    let results = posts.count().get_result(connection).expect("s");
    println!("{:?}",results);
    return Json::<Vec<Post>>(results)
}

#[post("/", data = "<blog_post>")]
async fn create_blog_post(blog_post: Json<NewPost>) -> Json<NewPost> {
    use crate::schema::posts::dsl::posts;
    let mut connection = establish_connection();
    diesel::insert_into(posts)
    .values(NewPost {title: "test 2".to_string(),edited: false})
    .execute(&mut connection)
    .expect("E");
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