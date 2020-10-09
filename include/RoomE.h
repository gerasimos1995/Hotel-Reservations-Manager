#ifndef ROOME_H
#define ROOME_H

#include "Room.h"
#include "Reservation.h"

class RoomE : public Room
{
    public:
        RoomE();
        ~RoomE();
         bool addReservation(Reservation*);

    protected:

    private:
};

#endif // ROOME_H
