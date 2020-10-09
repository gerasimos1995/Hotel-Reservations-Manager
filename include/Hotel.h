#ifndef HOTEL_H
#define HOTEL_H
#include "Reservation.h"
#include "Room.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>


class Hotel
{
    public:
        Hotel();
        ~Hotel();
        std:: string getHotelName();
        void setHotelName(std::string );
        void addRoom(Room*);
        Room* getRoomById(unsigned int);
        Reservation* getReservationById(unsigned int);
        void displayRooms();
        void displayReservations();
        bool addReservationToRoom(Reservation*, unsigned int);
        int addReservation(Reservation*);
        int getHotelReservationsSize();
        Reservation* getReservation(int );
        void cancelReservation(unsigned int );
        void displayPlanOfReservations();
        double measureProfit();

    protected:

    private:

        std::string hotelName;
        std::vector <Reservation*> hotelReservations;
        std::vector <Room*> hotelRooms;
};

#endif // HOTEL_H
