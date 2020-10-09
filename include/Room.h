#ifndef ROOM_H
#define ROOM_H
#include <stdio.h>
#include <cstddef>
#include <vector>
//#include "Reservation.h"

class Reservation;

class Room
{
    public:
        Room();
        ~Room();
        void setMaxCapacity(int);
        int getMaxCapacity();
        void setPricePerPerson(double);
        double getPricePerPerson();
        void setRoomId(int);
        float occupancy();
        unsigned int getRoomId();
        virtual bool addReservation(Reservation*);
        virtual double pricing();
        virtual bool cancel(unsigned int );
        void displayAvailability();
        Reservation* availability[30];

    protected:

    private:
        static int roomCounter;
        int maxCapacity;
        double pricePerPerson;
        unsigned int roomId;
};

#endif // ROOM_H
