//#pragma once
#ifndef SLOT
#define SLOT
#include "Car.cpp"
#include "iostream"
class Slot
{
    private:
        Car* parkedCar;
        int slotNumber;
    public :
        Slot( int slotNumber)
        {
            this->slotNumber= slotNumber;
           // this->parkedCar = new Car();
        }
        ~Slot(){}

        int getSlotNumber()
        {
            return slotNumber;
        }

        Car* getCar()
        {
            return this->parkedCar;
        }

        bool isSlotFree()
        {
            return parkedCar == nullptr;
        }

        void assignCar(Car* car)
        {
            this->parkedCar = car;
        }

        void unassignCar()
        {
            this->parkedCar = nullptr;
        }

};
#endif