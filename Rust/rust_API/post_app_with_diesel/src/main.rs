#[macro_use] extern crate rocket;
mod models;
mod db;
mod schema;

use db::establish_connection;
use models::{NewPost,Post};
use rocket::serde::json::Json;
use diesel::{RunQueryDsl};


#[get("/")]
fn index() -> &'static str {
    ""
}
#[get("/all")]
fn get_all_posts() -> Json<Vec<Post>> {
    use crate::schema::posts::dsl::*;

    let connection = &mut establish_connection();
    // let results = posts.filter(edited.eq(false)).limit(4).load::<Post>(connection).expect("Error loading posts");
    let results = posts.load::<Post>(connection).expect("");

    return Json::<Vec<Post>>(results)
}

#[post("/", data = "<blog_post>")]
async fn create_blog_post(blog_post: Json<NewPost<'_>>) -> Json<Post> {
    use crate::schema::posts::dsl::posts;
    let connection = &mut establish_connection();

    let postcreate = diesel::insert_into(posts)
    .values(&blog_post.into_inner())
    .get_result::<Post>(connection).unwrap();
    
    Json(postcreate)
}
#[launch]
fn rocket() -> _ {
    let rocket = rocket::build();
    rocket
        .mount("/", routes![index,get_all_posts,create_blog_post])
    }