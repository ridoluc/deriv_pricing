#ifndef MCESTIMATOR_H
#define MCESTIMATOR_H

#include"PayOff.h"

double MCEstimator(
                     const PayOff &    claim,
                     const double      T,
                     const double      r,
                     const double      sigma,
                     const double      S_0,
                     const unsigned int sample )
{

   RandVar r_var;


   const double   drift    = (r - 0.5 * sigma * sigma) * T;
   const double   std_dev  = sigma * sqrt(T);

   double P_avg = 0; 
   double S_T, n;


   for(int i = 0; i< sample; i++)
   {
      n = r_var.getNormal();
      S_T = S_0 * exp( drift + std_dev * n );
      P_avg += claim.payoff(S_T);
   } 

   P_avg = exp(- r * T) * P_avg / sample;

   return P_avg;
}


#endif // MCESTIMATOR_H