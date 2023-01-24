-- Your SQL goes here
CREATE TABLE posts (
    id serial NOT NULL,
    title character VARYING(255) NOT NULL,
    edited boolean NOT NULL DEFAULT FALSE,
    CONSTRAINT post_pkey PRIMARY KEY (id)
);