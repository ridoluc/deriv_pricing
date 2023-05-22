#ifndef MCESTIMATOR_H
#define MCESTIMATOR_H

#include"PayOff.h"
#include"StockPath.h"

double MCEstimator(  const PayOff &       claim,
                     StockPath &          stock,
                     const double         rf_rate,
                     const unsigned int   sample_size)
{

   RandVar r_var;

   double P_avg = 0; 
   double S_T;

   for(int i = 0; i< sample_size; i++)
   {
      S_T = stock.generatePath().back();
      P_avg += claim.payoff(S_T);
   } 

   P_avg = exp(- rf_rate * stock.getPeriod()) * P_avg / sample_size;

   return P_avg;
}


#endif // MCESTIMATOR_H