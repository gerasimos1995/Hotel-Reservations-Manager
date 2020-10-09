#include "Room.h"

#include "Reservation.h"

int Room::roomCounter = 0;

Room::Room()
{
    int i;
    roomCounter++;
    roomId = roomCounter;

    for (i=0;i<30;i++){
        availability[i]= new Reservation;
    }
    for (i=29;i>=0;i--){
        delete availability[i];
    }

    for (i=29;i>=0;i--){
        availability[i]= NULL;
    }
}

Room::~Room()
{
}

void Room::setMaxCapacity(int maxcapacity){
    maxCapacity = maxcapacity;
}

int Room::getMaxCapacity(){
    return maxCapacity;
}

void Room::setPricePerPerson(double priceperperson){
    pricePerPerson = priceperperson;
}

double Room::getPricePerPerson(){
    return pricePerPerson;
}

void Room::setRoomId(int roomid){
    roomId = roomid;
}

unsigned int Room::getRoomId(){
    return roomId;
}

bool Room::addReservation(Reservation *res){
    bool flag=true;

    int i;
    int temp1=res->getArrival();
    int temp2=res->getStayingDays();
    int temp3=res->getNumOfPersons();

    if(temp3<=getMaxCapacity()){
        for (i=temp1-1;i<(temp2+temp1-1);i++){
            if(!(this->availability[i]==NULL)){
                flag = false;
            }
        }
        if (flag==true){
            for (i=temp1-1;i<(temp2+temp1-1);i++){
                availability[i] = res;
            }
            res->assignRoom(this);
        }
        return flag;
    }else{
        return false;
    }
}

float Room::occupancy(){
    int i;
    float count=0;

    for(i=0;i<30;i++){
        if(availability[i]!=NULL){
            count++;
        }
    }
    return 100*(count/30);
}

double Room::pricing(){
    int i;
    double price=0;

    for (i=0;i<30;i++){
        if(availability[i]!=NULL){
            price = price +  availability[i]->getNumOfPersons()*getPricePerPerson();
        }
    }
    return price;
}


bool Room::cancel(unsigned int  id){
    bool flag=false;
    int i;

    for (i=0;i<30;i++){
            if(availability[i]!=NULL){
                if((availability[i]->getReservationId())== id){
                    availability[i] = NULL;
                    flag = true;
                }
            }
    }
    return flag;
}

void Room::displayAvailability(){
    int i;

    //bool flag = true;
    for (i=0;i<30;i++){
        if (availability[i]!=NULL){
            std::cout << "* ";
        }else{
            std::cout << "_ ";
        }
    }
    return;
}
