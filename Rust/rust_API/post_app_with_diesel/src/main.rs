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
    println!("{:?}",results);
    return Json::<Vec<Post>>(results)
}

#[post("/", data = "<blog_post>")]
async fn create_blog_post(blog_post: Json<NewPost<'_>>) -> Json<NewPost> {
    use crate::schema::posts::dsl::posts;
    let mut connection = establish_connection();

    diesel::insert_into(posts)
    .values(&blog_post.into_inner())
    .execute(&mut connection)
    .expect("E");
    
    Json(NewPost { title: "jdd" })
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