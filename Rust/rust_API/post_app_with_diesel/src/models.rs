use diesel::{Insertable, Queryable,AsChangeset};
use serde::{Serialize,Deserialize};

#[derive(Debug,AsChangeset,Queryable,Serialize, Deserialize,Insertable)]
#[diesel(table_name = posts)]
pub struct Post {
    pub id: i32,
    pub title: String,
    pub edited: bool,
}
diesel::table! {
    posts (id) {
        id -> Int4,
        title -> Varchar,
        edited -> Bool,
    }
}
