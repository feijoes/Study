
use diesel::{Insertable, Queryable,AsChangeset, pg,FromSqlRow};
use serde::{Serialize,Deserialize};
use crate::schema::posts;
#[derive(Debug,AsChangeset,Queryable,Serialize, Deserialize,Insertable)]
#[diesel(table_name = posts)]
pub struct NewPost {
    pub title: String,
    pub edited: bool,
}
#[derive(FromSqlRow,Debug,AsChangeset,Serialize, Deserialize,Insertable)]
#[diesel(table_name = posts)]
pub struct Post {
    pub id: i32,
    pub title: String,
    pub edited: bool,
}