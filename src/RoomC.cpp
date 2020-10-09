#include "RoomC.h"

RoomC::RoomC():Room()
{
    //ctor
}

RoomC::~RoomC()
{
    //dtor
}

void RoomC::setMinDays(int min_days){

    minDays= min_days;
}

void RoomC::setMinPersons(int min_persons){

    minPersons= min_persons;
}

int RoomC::getMinDays(){

    return minDays;
}

int RoomC::getMinPersons(){

    return minPersons;
}

bool  RoomC::addReservation(Reservation*res){
bool flag=true;
    //bool flag2 = false;
    int i;
    int temp1=res->getArrival();
    int temp2=res->getStayingDays();
    int temp3=res->getNumOfPersons();

    if(temp3>=this->getMinPersons() && temp2>=this->getMinDays()){

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

        }
        else{

            return false;
        }

    }
    else{

        return false;
    }
}

