#include <iostream>
#include <stdlib.h>
#include "Reservation.h"
#include "Room.h"
#include "Hotel.h"
#include "RoomA.h"
#include "RoomB.h"
#include "RoomC.h"
#include "RoomD.h"
#include "RoomE.h"

using namespace std;

int main()
{

    unsigned int choice,arrival,staying,persons,res_id,room_id,p,size_res,index,temp_id;
    string clientname,answer;

    Hotel hotel;
    Room room1;
    Room room2;
    Room room3;
    Room room4;
    RoomA room5;
    RoomB room6;
    RoomC room7;
    RoomD room8;
    RoomE room9;
    Room room10;

    room1.setMaxCapacity(3);
    room1.setPricePerPerson(10);

    room2.setMaxCapacity(4);
    room2.setPricePerPerson(10);

    room3.setMaxCapacity(6);
    room3.setPricePerPerson(10);

    room4.setMaxCapacity(2);
    room4.setPricePerPerson(10);

    room5.setPricePerDay(10);
    room5.setMaxCapacity(5);

    room6.setPricePerDay(50);
    room6.setMaxCapacity(7);
    room6.setDiscountPerDay(10);

    room7.setMaxCapacity(7);
    room7.setPricePerPerson(10);
    room7.setMinDays(3);
    room7.setMinPersons(3);

    room8.setMaxCapacity(7);
    room8.setPricePerPerson(10);
    room8.setLuxValue(5);

    room9.setMaxCapacity(5);
    room9.setPricePerPerson(10);

    room10.setMaxCapacity(6);
    room10.setPricePerPerson(12);

    hotel.addRoom(&room1);
    hotel.addRoom(&room2);
    hotel.addRoom(&room3);
    hotel.addRoom(&room4);
    hotel.addRoom(&room5);
    hotel.addRoom(&room6);
    hotel.addRoom(&room7);
    hotel.addRoom(&room8);
    hotel.addRoom(&room9);




    do {
        cout << "Press 1. to Continue " << endl;
        cout << "Press 2. to Add Reservation " << endl;
        cout << "Press 3. to Cancel Reservation " << endl;
        cout << "Press 4. to Display Reservations " << endl;
        cout << "Press 5. to Display Rooms " << endl;
        cout << "Press 6. to Display Plan of Reservations " << endl;
        cout << "Press 7. to Display Total Profit " << endl;
        cout << "Press 8. to Exit the Simulation " <<endl;

        cin >> choice;
        if (choice == 1){
            Reservation *res=new Reservation();
            cout << "Give client name :" << endl;
            cin >> clientname;
            cout << "Give the day of arrival :" << endl;
            cin >> arrival;
            cout << "Give the number of days :" << endl;
            cin >> staying;
            cout << "Give the number of persons :" << endl;
            cin >> persons;
            res->setArrival(arrival);
            res->setClientName(clientname);
            res->setStayingDays(staying);
            res->setNumOfPersons(persons);
            hotel.addReservation(res);
            p = rand() % 100 + 1;
            cout << "P is: " << p << endl;
            if ( p>=1 && p<=25){

                size_res = hotel.getHotelReservationsSize();
                index = rand() % size_res;
                temp_id = hotel.getReservation(index)->getReservationId();
                hotel.cancelReservation(temp_id);

            }
        }
        else if (choice == 2 ){
            Reservation *res=new Reservation();
            cout << "Give client name :" << endl;
            cin >> clientname;
            cout << "Give the day of arrival :" << endl;
            cin >> arrival;
            cout << "Give the number of days :" << endl;
            cin >> staying;
            cout << "Give the number of persons :" << endl;
            cin >> persons;
            cout << "Do you want to give a room id?(Yes/No)" << endl;
            cin >> answer;
            res->setArrival(arrival);
            res->setClientName(clientname);
            res->setStayingDays(staying);
            res->setNumOfPersons(persons);
            if ( answer.compare("Yes")==0){
                cout << "Give the room's id: " << endl;
                cin >> room_id;
                hotel.addReservationToRoom(res,room_id);
            }else{
                hotel.addReservation(res);
            }
        }else if (choice == 3){
            cout << "Give Reservation's id : " << endl;
            cin >> res_id;
            hotel.cancelReservation(res_id);
        }else if (choice == 4){
            hotel.displayReservations();
        }else if (choice == 5){
            hotel.displayRooms();
        }else if (choice == 6){
            hotel.displayPlanOfReservations();
        }else if (choice == 7){
            cout << "Total profit is :" << hotel.measureProfit() << endl;
        }
        cout << endl;
        }while (choice !=8);

        cout << "End of simulation!" << endl;
        return 0;
    }
