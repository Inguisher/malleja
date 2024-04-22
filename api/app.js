var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var LoginRouter = require('./routes/Login');
var accountRouter = require('./routes/account');
var indexRouter = require('./routes/index');
var CustomerRouter = require('./routes/Customer');
var BankCardRouter = require('./routes/BankCard');
var ActionRouter = require('./routes/Action');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/account', accountRouter);
app.use('/Login', LoginRouter);
app.use('/', indexRouter);
app.use('/Customer', CustomerRouter);
app.use('/BankCard', BankCardRouter);
app.use('/Action', ActionRouter);

module.exports = app;
