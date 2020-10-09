#include "RoomA.h"

RoomA::RoomA():Room()
{
    //ctor
}

RoomA::~RoomA()
{
    //dtor
}

void RoomA::setPricePerDay(int price){

    pricePerDay = price;

}

int RoomA::getPricePerDay(){

    return pricePerDay;

}

double RoomA::pricing(){

    int i;

    double price=0;

    for (i=0;i<30;i++){

        if(availability[i]!=NULL){


            price = price +  getPricePerDay();

        }

    }



    return price;

}
