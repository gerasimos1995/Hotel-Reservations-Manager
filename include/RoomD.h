#ifndef ROOMD_H
#define ROOMD_H

#include "Room.h"
#include "Reservation.h"


class RoomD : public Room
{
    public:
        RoomD();
        ~RoomD();
        void setLuxValue(int);
        int getLuxValue();
         double pricing();

    protected:

    private:
        int luxvalue;
};

#endif // ROOMD_H
