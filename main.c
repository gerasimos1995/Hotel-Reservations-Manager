#include <iostream>
#include <Reservation.h>
#include <Room.h>

using namespace std;

int main()
{
    Room room1;
    Room room2;
    Room room3;
    Room room4;
    cout << "Room1 id: " << room1.getRoomId() << endl;
    cout << "Room2 id: " << room2.getRoomId() << endl;
    cout << "Room3 id: " << room3.getRoomId() << endl;
    cout << "Room4 id: " << room4.getRoomId() << endl;
    //cout << "Reservation1 id: " + reserv1.getReservationId() << endl;
    return 0;
}
