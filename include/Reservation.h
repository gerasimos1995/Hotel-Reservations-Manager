#ifndef RESERVATION_H
#define RESERVATION_H
#include <stdio.h>
#include <string>
#include <iostream>
//#include "Room.h"

class Room;

class Reservation
{
    public:
        Reservation();

        ~Reservation();
        void setClientName(std::string);
        std::string getClientName();
        void setArrival(int);
        int getArrival();
        void setStayingDays(int);
        int getStayingDays();
        void setNumOfPersons(int);
        int getNumOfPersons();
        unsigned int getReservationId();
        void assignRoom(Room *);
        void displayRes();
        Room* getRoom();

    protected:

    private:
        static int reservationCounter;
        std::string clientName;
        unsigned int dayOfArrival;
        unsigned int stayingDays;
        unsigned int numOfPersons;
        unsigned int reservationId;
        Room* room ;
};

#endif // RESERVATION_H
