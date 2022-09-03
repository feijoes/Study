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
app.use(express.urlencoded({extended: true}));
app.use(cors());
app.use(express.static(path.join(__dirname, 'public')));

app.use(require('./routes'));


app.listen(3000);
 