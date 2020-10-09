#ifndef ROOMC_H
#define ROOMC_H
#include "Room.h"
#include "Reservation.h"

class RoomC : public Room
{
    public:
        RoomC();
        ~RoomC();
         bool addReservation(Reservation*);
        void setMinPersons(int);
        void setMinDays(int);
        int getMinPersons();
        int getMinDays();

    protected:

    private:
        int minPersons;
        int minDays;
};

#endif // ROOMC_H
