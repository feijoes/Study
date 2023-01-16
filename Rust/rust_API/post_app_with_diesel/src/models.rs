use diesel::{Insertable, AsChangeset, Queryable};

use crate::schema::posts;

#[derive(Insertable)]
#[table_name = "posts"]
pub struct NewPost<'a> {
    pub title: &'a str,
    pub edited: &'a str,
}

#[derive(Debug,AsChangeset,Queryable)]
pub struct Post {
    pub id: i32,
    pub title: String,
    pub edited: bool,
}