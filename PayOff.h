#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
public:
   PayOff(){};
   virtual double payoff(double spot_price) const = 0;
   ~PayOff(){};
private:
};

#endif // PAYOFF_H