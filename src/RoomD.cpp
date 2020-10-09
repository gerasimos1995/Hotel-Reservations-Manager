#include "RoomD.h"

RoomD::RoomD():Room()
{
    //ctor
}

RoomD::~RoomD()
{
    //dtor
}

void RoomD::setLuxValue(int lux_value){

    luxvalue = lux_value;
}

int RoomD::getLuxValue(){

    return luxvalue;
}


double RoomD::pricing(){


    int i;

    double price=0;

    for (i=0;i<30;i++){

        if(availability[i]!=NULL){

            price = price +  availability[i]->getNumOfPersons()*getPricePerPerson();

        }

    }


    return price*getLuxValue();
}

