
use diesel::{Insertable, Queryable,AsChangeset};
use serde::{Serialize,Deserialize};
use crate::schema::posts;
#[derive(Debug,AsChangeset,Queryable,Serialize, Deserialize,Insertable)]
#[diesel(table_name = posts)]
pub struct NewPost {
    pub id: i32,
    pub title: String,
    pub edited: bool,
}

