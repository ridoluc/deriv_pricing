#ifndef ASIANOPTION_H
#define ASIANOPTION_H

#include "StockPath.h"

class AsianCallOption: public CallOption, public PayOff
{
public:
   AsianOption(double _expiry, double _strike, StockPath & _path):CallOption(_expiry, _strike),path(_path);

   double averagePathValue();

private:
   StockPath path;
}

double AsianCallOption::averagePathValue()
{
   std::vector<double> p = path.generatePath();

   double avg


   for(std::vector<double>::iterator i = p.begin(); i != p.end(); i++)
   {
      avg += *i;
   }

   return avg/p.size();
}

#endif //ASIANOPTION_H