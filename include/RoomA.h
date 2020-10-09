#ifndef ROOMA_H
#define ROOMA_H
#include "Room.h"


class RoomA : public Room
{
    public:
        RoomA();
         ~RoomA();
         void setPricePerDay(int);
         int getPricePerDay();
          double pricing();

    protected:

    private:
        int pricePerDay;
};

#endif // ROOMA_H
