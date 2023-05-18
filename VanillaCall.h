#ifndef VANILLACALL_H
#define VANILLACALL_H

#include "PayOff.h"

class CallOption: public PayOff
{
public:
   CallOption();
   double payoff(double spot) const;
   ~CallOption();
private:
   double strike;
};

#endif // VANILLACALL_H