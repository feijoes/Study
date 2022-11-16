const express = require('express');
const cors = require('cors');
const path = require('path');
const passport = require('passport')

require('dotenv').config();
require('./config/database');
require('./models/user');
require('./config/passport')(passport);


const app = express();
app.use(passport.initialize());


app.use(express.json());

app.use((_, res, next) => {
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, PUT, PATCH, DELETE');
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type, Authorization');
    next();
});

app.use(express.json());
app.use(express.urlencoded({extended: true}));
app.use(cors());
app.use("/routes",require('./routes'));

app.listen(5000);