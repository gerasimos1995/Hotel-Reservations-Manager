#include "Reservation.h"

#include "Room.h"
int Reservation::reservationCounter = 0;


Reservation::Reservation()
{
    reservationCounter++;
    reservationId = reservationCounter;
}

Reservation::~Reservation()
{
}

void Reservation::setClientName(std::string clientname){
    clientName = clientname;
}

std::string Reservation::getClientName(){
    return clientName;
}

void Reservation::setArrival(int arrival){
    dayOfArrival = arrival;
}

int Reservation::getArrival(){
    return dayOfArrival;
}

void Reservation::setStayingDays(int stayingdays){
    stayingDays = stayingdays;
}

int Reservation::getStayingDays(){
    return stayingDays;
}

void Reservation::setNumOfPersons(int numofpersons){
    numOfPersons = numofpersons;
}

int Reservation::getNumOfPersons(){
    return numOfPersons;
}

unsigned int Reservation::getReservationId(){
    return reservationId;
}

Room* Reservation::getRoom(){
    return room;
}

void Reservation:: assignRoom(Room *newroom){
   room = newroom;
}

void Reservation:: displayRes(){
    std:: cout << "Reservation Id " << getReservationId() << std::endl;
    std:: cout << "Reservation Arrival " <<  getArrival() <<std::endl;
    std:: cout << "Reservation Staying Days " <<  getStayingDays() << std:: endl;
    std:: cout << "Number of Persons " << getNumOfPersons() << std:: endl;
    std:: cout << "Room id " << room->getRoomId() << std::endl;
}
