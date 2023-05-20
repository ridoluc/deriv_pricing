#ifndef RANDOMVARIABLE_H
#define RANDOMVARIABLE_H

#include<cstdlib>
#include<vector>

class RandVar
{
public:
   RandVar();
   RandVar(unsigned int seed);
   ~RandVar() {};

   double getUniform() ;
   double getNormal() ;
   
   std::vector<double> getUniform(const unsigned int N) ;
   std::vector<double> getNormal(const unsigned int N) ;


};

RandVar::RandVar() {}

RandVar::RandVar(unsigned int seed)
{
   std::srand(seed);
}

double RandVar::getUniform()
{
   return (double) std::rand()/RAND_MAX;
}

double RandVar::getNormal() 
{
   /* To be improved. 
      - Wasting one variable 
      - check for machine 0
   */
   double u1 = getUniform();
   double u2 = getUniform();

   double r    = std::sqrt( -2 * std::log(u1) );
   double n1   = r * cos(2* M_PI * u2);

   return n1;
}


std::vector<double> RandVar::getUniform(const unsigned int N) 
{
   std::vector<double> res;

   for(int i = 0; i<N; i++)
   {
      res.push_back(getUniform());
   }

   return res;
}

std::vector<double> RandVar::getNormal(const unsigned int N) 
{
   std::vector<double> res;

   for(int i = 0; i<N; i++)
   {
      res.push_back(getNormal());
   }

   return res;
}



#endif //RANDOMVARIABLE_H