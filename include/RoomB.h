#ifndef ROOMB_H
#define ROOMB_H
#include "RoomA.h"

class RoomB : public RoomA
{
    public:
        RoomB();
        ~RoomB();
         double pricing();
        void setDiscountPerDay(int);
        int getDiscountPerDay();
         bool cancel();

    protected:

    private:
        int discountPerDay;
};

#endif // ROOMB_H
