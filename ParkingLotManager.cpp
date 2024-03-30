//#pragma once
//#include "Car.cpp"
#ifndef PARKINGLOTMANAGER
#define PARKINGLOTMANAGER
#include "ParkingLot.cpp"
//#include "Slot.cpp"
#include "ParkingStrategy/BaseStrategy.cpp"
#include "ParkingStrategy/UserStrategy.cpp"
#include "unordered_map"
class ParkingLotManager
{
    private:
        ParkingLot* parkingLot;
        BaseStrategy* parkingStrategy;

    public:
        void createParkingLot(ParkingLot* parkingLot, BaseStrategy* parkingStrategy)
        {
            if(this->parkingLot==nullptr)
            {
                throw ParkingLotException ("ALready exists");
            }
            this->parkingLot = parkingLot;
            this->parkingStrategy = parkingStrategy;
            for (int i=i;i<=parkingLot->getCapacity();i++)
            {
                parkingStrategy->addSlot(i);
            }
        }
        
        int park(Car* car)
        {
            int nextFreeSlot = parkingStrategy->getNextSlot();
            parkingLot->park(car,nextFreeSlot);
            parkingStrategy->removeSlot(nextFreeSlot);
            return nextFreeSlot;
        }

        void makeSlotFree(int slotNumber)
        {
            parkingLot->makeSlotFree(slotNumber);
            parkingStrategy->addSlot(slotNumber);
        }

        std::vector<Slot*>  getOccupiedSlot()
        {
            std::vector<Slot*> occupiedSlot;
            std::unordered_map<int,Slot*> allSlots = parkingLot->getSlots();

            for (int i=1;i<=parkingLot->getCapacity();i++)
            {
                if(allSlots.find(i)!=allSlots.end())
                {
                    Slot* slot = allSlots[i];
                    if(!slot->isSlotFree())
                    {
                        occupiedSlot.push_back(slot);                        
                    }
                }
            }
            return occupiedSlot;
        }

        std::vector<Slot*> getSlotsForModel(std::string &model)
        {
            std::vector<Slot*> occupiedSlot = getOccupiedSlot();
            std::vector<Slot*> slotsForModel ;
            for (Slot* slot : occupiedSlot)
            {
                if(slot->getCar()->getModel()==model)
                {
                    slotsForModel.push_back(slot);
                }
            }
            return slotsForModel;
        }
};
#endif