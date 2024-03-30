#ifndef PARKINGLOT
#define PARKINGLOT
#include <map>
#include "exception/exception.cpp"
//#include "Car.cpp"
#include "Slot.cpp"
#include "iostream"
//#pragma once
/*
Parking Lot Class 
*/
class ParkingLot

{
    private:
        static const int MAX_CAPACITY = 100;
        int capacity;
        std::unordered_map<int,Slot*> slots;

        Slot* getSlot(int slotNumber)
        {

            Slot* temp = new Slot(slotNumber);

            slots[slotNumber] = temp;

            return temp;
        }
    public:
        ParkingLot(const int capacity)
        {
            if(capacity>MAX_CAPACITY||capacity<=0)
            {
                throw ParkingLotException();
            }
            this->capacity = capacity;
        }

        int getCapacity()
        {
            return this->capacity;
        }

        std::unordered_map<int,Slot*> getSlots()
        {
            return slots;
        }

        Slot* park(Car *car,const int slotNumber)
        {
            Slot* slot = getSlot(slotNumber);

            slot->assignCar(car);
            return slot;
        }

        Slot* makeSlotFree(const int slotNumber)
        {
            Slot* slot = getSlot(slotNumber);
            slot->unassignCar();
            return slot;
        }
};
#endif