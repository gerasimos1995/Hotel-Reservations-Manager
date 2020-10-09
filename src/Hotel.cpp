#include "Hotel.h"

Hotel::Hotel()
{
}

Hotel::~Hotel()
{
}

std::string Hotel::getHotelName(){
    return hotelName;
}

void Hotel::setHotelName(std::string name){
    hotelName = name;
}

void Hotel::addRoom(Room* room){
    hotelRooms.push_back(room);
}

Room* Hotel::getRoomById(unsigned int id){
    unsigned int i;

    for (i=0; i<hotelRooms.size(); i++){
        if(hotelRooms[i]->getRoomId() == id){
            return hotelRooms[i];
        }
    }
    return NULL;
}

Reservation* Hotel::getReservationById(unsigned int id){
    unsigned int i;

    for (i=0; i<hotelReservations.size(); i++){
        if (hotelReservations[i]->getReservationId() == id){
             return hotelReservations[i];
        }
    }
    return NULL;
}

bool Hotel::addReservationToRoom(Reservation* res, unsigned int id){
    bool flag=true;
    flag=getRoomById(id)->addReservation(res);

    if(flag==true){
        hotelReservations.push_back(res);
        std::cout << "Adding reservation was succesful!\n" << std::endl;
        return flag;
    }else{
        std::cout << "Adding reservation was not succesful!\n" << std::endl;
        return flag;
    }

}

int Hotel::addReservation(Reservation* res){
    bool flag=false;
    unsigned int i,index,count=0;

    for(i=0;i<hotelRooms.size();i++){
        flag = hotelRooms[i]->addReservation(res);
        index = i;
        count++;
        if(flag == true){
            std::cout << "Adding reservation to room " << hotelRooms[index]->getRoomId() << " was successful!" << std::endl;
            hotelReservations.push_back(res);
            return hotelRooms[index]->getRoomId();
        }else if(count==hotelRooms.size() && flag == false){
            std::cout << "Adding reservation was not successful!" << std::endl;
            return 0;
        }
    }
}

void Hotel::cancelReservation(unsigned int id){
    unsigned int i,temp;
    bool found=false;

    for (i=0; i<hotelReservations.size(); i++){
        if (hotelReservations[i]->getReservationId() == id){
            found = true;
            temp=i;
            break;
        }
    }
    if (found == false){
        std::cout << "No reservation found with given id." << std::endl;;
        return;
    }

    int tempid=hotelReservations[temp]->getReservationId();
    hotelReservations[temp]->getRoom()->cancel(id);
    hotelReservations.erase(hotelReservations.begin() + temp);
    std::cout << "Reservation "<< tempid << " deleted successfully!\n" << std::endl;
}




void Hotel::displayPlanOfReservations(){

    unsigned int i,j;
    std::cout << std::endl;
    std::cout << "Room\t" << "01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30" << "\n";

    for (i=0; i<hotelRooms.size(); i++){
        std::cout<< hotelRooms[i]->getRoomId() << "\t";
        for (j=0; j<30; j++){
            if( hotelRooms[i]->availability[j]!=NULL ){
                std::cout << "*  ";
            }else{
                std::cout << "_  ";
            }
        }
        std::cout<<"\n";
    }
}

void Hotel::displayRooms(){

    unsigned int i;

    std::cout << std::endl;

    std::cout << "Room's Id is :"<< std::endl;
    for(i=0; i<hotelRooms.size(); i++){
        std::cout << hotelRooms[i]->getRoomId() << std::endl;
    }
    std::cout<<std::endl;
    std::cout << "Room's Occupancy is :"<<std::endl;
    for(i=0; i<hotelRooms.size(); i++){
        std::cout << hotelRooms[i]->occupancy() << std::endl;
    }
    std::cout<<std::endl;
    std::cout << "Room's Price is :"<<std::endl;
    for(i=0; i<hotelRooms.size(); i++){
        std::cout << hotelRooms[i]->pricing() << std::endl;
    }

}
double Hotel::measureProfit(){
    unsigned int i;
    double sum=0;

    for (i=0; i<hotelRooms.size(); i++){
        sum = sum + hotelRooms[i]->pricing();
    }
    return sum;
}

void Hotel::displayReservations(){

    unsigned int i;

    std::cout << std::endl;
    std::cout <<  "Reservation's Id is :"<< std::endl;
    for(i=0; i<hotelReservations.size(); i++){
        std::cout << hotelReservations[i]->getReservationId() << std::endl;
    }
    std::cout<<std::endl;
    std::cout  << "Reservation's client is :" << std::endl;
    for(i=0; i<hotelReservations.size(); i++){
        std::cout << hotelReservations[i]->getClientName() << std::endl;
    }
    std::cout<<std::endl;
    std::cout  << "Reservation's id of room is :" << std::endl;
    for(i=0; i<hotelReservations.size(); i++){
        std::cout << hotelReservations[i]->getRoom()->getRoomId() << std::endl;
    }

}

int Hotel::getHotelReservationsSize(){

    return hotelReservations.size();
}

Reservation* Hotel::getReservation(int index){

    return hotelReservations[index];

}
