const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const BankCard = {
  getById: function(id, callback) {
    return db.query('SELECT * FROM BankCard WHERE BankCardID=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('SELECT * FROM BankCard', callback);
  },
  add: function(BankCard, callback) {
    bcrypt.hash(BankCard.PinCode, saltRounds, function(err, hash) {
      return db.query
      ('INSERT INTO BankCard (CardNum, PinCode, AccountID, Closed) VALUES (?,?,?,?)',
      [BankCard.CardNum, hash, BankCard.AccountID, BankCard.Closed], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('DELETE FROM BankCard WHERE BankCardID=?', [id], callback);
  },
  update: function(id, BankCard, callback) {
    bcrypt.hash(BankCard.PinCode, saltRounds, function(err, hash) {
    return db.query(
      'UPDATE BankCard SET CardNum=?, PinCode=?, AccountID=? WHERE BankCardID=?',
      [BankCard.CardNum, hash, BankCard.AccountID, id],
      callback);
    });
  },

  ClosedChange: function(CardNum, callback) {
    return db.query('UPDATE BankCard SET Closed=1 WHERE CardNum=?',[CardNum], callback);
  }
};
module.exports = BankCard;