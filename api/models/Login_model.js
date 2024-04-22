const db = require('../database');

const Login={
  checkPinCode: function(CardNum, callback) {
      return db.query('SELECT PinCode, Closed FROM BankCard WHERE CardNum = ?',[CardNum], callback); 
    }
};
          
module.exports = Login;