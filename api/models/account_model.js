const db = require('../database');

const account = {
  getById: function(id, callback) {
    return db.query('select Balance from account where AccountID=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  add: function(account, callback) {
    return db.query(
      'insert into account (AccountNum,Balance,Opened) values(?,?,CURDATE())',
      [account.AccountNum, account.Balance],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where AccountID=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(
      'update account set AccountNum=?,Balance=? where AccountID=?',
      [account.AccountNum, account.Balance, id],
      callback
    );
  }
};
module.exports = account;