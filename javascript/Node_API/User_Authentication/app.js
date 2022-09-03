const express = require('express');
const mongoose = require('mongoose');
const session = require('express-session');
var passport = require('passport');
var crypto = require('crypto');
var routes = require('./routes');
const connection = require('./config/database');
const MongoStore = require('connect-mongo')(session);
const app = express();
require('dotenv').config();
require('./config/passport');

const sessionStore = new MongoStore({mongooseConnection: connection, collection: 'session'})
app.use(session({
    secret: process.env.secret,
    resave: false,
    saveUninitialized: true,
    store: sessionStore,
    cookie:{
        maxAge: 1000 * 60 * 60 *24
    }
}))

app.use(express.json());
app.use(express.urlencoded({extended: true}));

app.use(passport.initialize());
app.use(passport.session());



app.use(routes);

app.listen(3000);