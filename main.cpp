#include<iostream>
#include<cmath>


#include "RandomVariable.h"
#include "MCEstimator.h"
#include "Stock.h"
#include "StockPath.h"
#include "CallPut.h"



int main()
{

   const int SAMPLE_SIZE = 10000000;

   // Pricing constants
   const double   r        = 0.05;     // Risk-free rate
   const double   sigma    = 0.05;     // root variance
   const double   S_0      = 3.0;      // initial stock value


   const double   strike   = 3.0;
   const double   expiry   = 1.0;

   Stock stock(S_0, r, sigma);
   StockPath stck_path(stock, expiry, 1);
   const CallOption call(expiry, strike);

   double resCall = MCEstimator(
      call,
      stck_path,
      r,
      SAMPLE_SIZE
   );


   std::cout << "Call price:   " << resCall  << '\n';

}

