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
   const double   sigma    = 0.05;      // root variance
   const double   S_0      = 3.0;      // initial stock value


   const double   strike   = 3.0;
   const double   expiry   = 1.0;

   const CallOption call(expiry, strike);
   const PutOption put(expiry, strike);

   // const Stock stck;

   double resCall = MCEstimator(
      call,
      expiry,
      r,
      sigma,
      S_0,
      SAMPLE_SIZE
   );
   
   double resPut = MCEstimator(
      put,
      expiry,
      r,
      sigma,
      S_0,
      SAMPLE_SIZE
   );


   std::cout << "Call price:   " << resCall  << '\n';
   // std::cout << "Put price:    " << resPut   << '\n';
   // std::cout << "Strike PV:    " << strike * exp(-r * expiry)   << '\n';
   // std::cout << "Check put/call parity:" << resCall - resPut + strike * exp(-r * expiry)   << '\n';


}

