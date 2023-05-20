#ifndef STOCKPATH_H
#define STOCKPATH_H

#include <vector>
#include "Stock.h"
#include "RandomVariable.h"

class StockPath : public Stock
{
public:
   StockPath(const Stock & _stock, double _period, unsigned long _steps);

   std::vector<double> generatePath();

private:
   unsigned long  steps;
   double         period_length;
   double         dt;
};

StockPath::StockPath(const Stock & _stock, double _period, unsigned long _steps)
   :Stock(_stock)
{
   steps          = _steps;
   period_length  = _period; 
   dt             = period_length / steps;
}

std::vector<double> StockPath::generatePath()
{
   RandVar rng;

   std::vector<double> res;

   double vol        = getVol() * sqrt(dt);
   double square_vol = getVol() * getVol() * dt;
   double drift      = getReturn() * dt - 0.5 * square_vol;

   double last = getSpot();
   res.push_back(last);

   for(int i = 0; i< steps; i++)
   {
      last = last * exp(drift + vol * rng.getNormal());
      res.push_back(last);
   }

   return res;
}


#endif //STOCKPATH_H