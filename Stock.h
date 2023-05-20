#ifndef STOCK_H
#define STOCK_H

#include "PayOff.h"

class Stock: public PayOff
{
public:
   Stock(double _spot, double _return, double _vol)
         : spot_price(_spot), returns(_return), volatility(_vol) {};
   // Stock(const Stock & _stock);

   double virtual payoff(double s) const {return s;}

   double getReturn() {return returns;}
   double getVol() {return volatility;}
   double getSpot() {return spot_price;}

private:
   double spot_price;
   double returns;
   double volatility;
};



#endif  //STOCK_H