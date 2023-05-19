#include<iostream>
#include<cmath>

#include "CallPut.h"

double NormalRand();

int main()
{

   const int SAMPLE_SIZE = 100000000;

   // Pricing constants
   const double   r        = 0.05;
   const double   sigma    = 0.1;
   const double   S_0      = 1.0;
   const double   K        = 1.0;
   const double   T        = 1.0;

   const double   drift    = (r - 0.5 * sigma * sigma) * T;
   const double   std_dev  = sigma * sqrt(T);

   double P_avg = 0; 
   double S_T, n;

   CallOption call(T, K);

   for(int i = 0; i< SAMPLE_SIZE; i++)
   {
      n = NormalRand();
      S_T = S_0 * exp( drift + std_dev * n );
      P_avg += call.payoff(S_T);
   } 

   P_avg = exp(r * T) * P_avg / SAMPLE_SIZE;
   
   std::cout << P_avg << '\n';

}

double UniformRand()
{
   return (double) std::rand()/RAND_MAX;
}
double NormalRand()
{
   double u1 = UniformRand();
   double u2 = UniformRand();

   double r    = std::sqrt( -2 * std::log(u1) );
   double n1   = r * cos(2* M_PI * u2);

   return n1;
}