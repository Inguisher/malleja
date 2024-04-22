const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

router.post('/', 
  function(request, response) {
    if(request.body.CardNum && request.body.PinCode){
      const CardNum = request.body.CardNum;
      const PinCode = request.body.PinCode;
      const Closed = request.body.Closed;
        login.checkPinCode(CardNum, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else {
            if (Closed, dbResult[0].Closed == 0) {
              if (dbResult.length > 0) {
                bcrypt.compare(PinCode, dbResult[0].PinCode, function (err, compareResult) {
                  if (compareResult) {
                    console.log("Success");
                    response.send(true);
                  }
                  else {
                    console.log("Wrong PinCode");
                    response.send(false);
                  }
                  response.end();
                }
                );
              }
              else {
                console.log("Card doesn't exist.");
                response.send(false);
              }
            }
            else {
              console.log("Card has been closed.")
              response.send(false);
            }
          }
        }
        );
      }
    else{
      console.log("CardNum or PinCode missing");
      response.send(false);
    }
  }
);

module.exports=router;