#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H


class VanillaOption
{
public:
   VanillaOption(double _expiry, double _strike): strike(_strike), expiry(_expiry){};
   ~VanillaOption() {}

   inline double getExpiry() const {return expiry;}
   inline double getStrike() const {return strike;}

protected:
   double expiry;
   double strike;
};




#endif // VANILLAOPTION_H