#include "CallPut.h"


CallOption::CallOption(double _expiry, double _strike): VanillaOption(_expiry, _strike){};

double CallOption::payoff(double spot) const
{
   double pf = spot - strike;
   return pf > 0. ? pf : 0.;
}

PutOption::PutOption(double _expiry, double _strike): VanillaOption(_expiry, _strike){};

double PutOption::payoff(double spot) const
{
   double pf = strike - spot;
   return pf > 0. ? pf : 0.;
}