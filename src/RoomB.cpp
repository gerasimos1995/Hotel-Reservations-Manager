#include "RoomB.h"

RoomB::RoomB():RoomA()
{
    //ctor
}

RoomB::~RoomB()
{
    //dtor
}

void RoomB :: setDiscountPerDay(int discount){

    discountPerDay = discount;
}

int RoomB::getDiscountPerDay(){

    return discountPerDay;
}

double RoomB::pricing(){

 int i;
double temp1 = getPricePerDay();
double temp2 = temp1;
    double price=0;

    for (i=0;i<30;i++){

        if(availability[i]!=NULL){

            price = price +  temp1;

            if ( (temp1 - getDiscountPerDay())> temp2/2){

                    temp1 = temp1 - getDiscountPerDay();

            }
            else if ( (temp1 - getDiscountPerDay())< temp2/2){

                temp1= temp2/2;
            }

        }

    }

    return price;

}

bool RoomB::cancel(){

    return false;

}
