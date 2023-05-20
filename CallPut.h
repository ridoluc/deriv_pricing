#ifndef CALLPUT_H
#define CALLPUT_H

#include "PayOff.h"
#include "VanillaOption.h"

class CallOption: public PayOff, public VanillaOption
{
public:
   CallOption(double _expiry, double _strike);
   virtual ~CallOption() {};

   double payoff(double spot) const;

private:
};

class PutOption: public PayOff, public VanillaOption
{
public:
   PutOption(double _expiry, double _strike);
   virtual ~PutOption() {};

   double payoff(double spot) const;

private:
};



#endif //CALLPUT_H