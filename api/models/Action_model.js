const db = require('../database');

const Action = {
  getById: function(id, callback) {
    return db.query('SELECT * FROM Action WHERE ActionID=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('SELECT * FROM Action', callback);
  },
  add: function(Action, callback) {
    return db.query(
      'CALL Transaction(?, ?)',
      [Action.AccountID, Action.Amount],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('DELETE FROM Action WHERE ActionID=?', [id], callback);
  },
  update: function(id, Action, callback) {
    return db.query(
      'UPDATE Action SET Description=?, Amount=? WHERE ActionID=?',
      [Action.Description, Action.Amount, id],
      callback
    );
  }
};
module.exports = Action;