#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

#include "PayOff.h"


class VanillaOption
{
public:
   VanillaOption(double, double);

   inline const double getExpiry() {return expiry;}
   inline const double getStrike() {return strike;}

protected:
   double expiry;
   double strike;
};

VanillaOption::VanillaOption(double _expiry, double _strike) : strike(_strike), expiry(_expiry)
{}



#endif // VANILLAOPTION_H