#include "RoomE.h"

RoomE::RoomE():Room()
{
    //ctor
}

RoomE::~RoomE()
{
    //dtor
}


bool  RoomE::addReservation(Reservation*res){
bool flag=true;
    //bool flag2 = false;
    int i;
    int temp1=res->getArrival();
    int temp2=res->getStayingDays();
    int temp3=res->getNumOfPersons();



        if(temp3==getMaxCapacity()){
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
