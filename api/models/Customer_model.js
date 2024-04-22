const db = require('../database');

const Customer = {
  getById: function(id, callback) {
    return db.query('SELECT * FROM Customer WHERE CustomerID=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('SELECT * FROM Customer', callback);
  },
  add: function(Customer, callback) {
    return db.query(
      'INSERT INTO Customer (FirstName, LastName, BirthDate, Address, PhoneNum) VALUES (?, ?, ?, ?, ?)',
      [Customer.FirstName, Customer.LastName, Customer.BirthDate, Customer.Address, Customer.PhoneNum],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('DELETE FROM Customer WHERE CustomerID=?', [id], callback);
  },
  update: function(id, Customer, callback) {
    return db.query(
      'UPDATE Customer SET FirstName = ?, LastName = ?, BirthDate = ?, Address = ?, PhoneNum = ? WHERE CustomerID=?',
      [Customer.FirstName, Customer.LastName, Customer.BirthDate, Customer.Address, Customer.PhoneNum, id],
      callback
    );
  }
};
module.exports = Customer;