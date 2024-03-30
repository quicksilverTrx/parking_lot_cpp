#ifndef USERSTRATEGY
#define USERSTRATEGY
#include <set>
#include "BaseStrategy.cpp"
//#pragma once
class UserStrategy : public BaseStrategy
{
    private:
        std::set<int> filledSlot;

    public:

        void addSlot(int slotNumber) override
        {
            this->filledSlot.insert(slotNumber);
        }

        void removeSlot(int slotNumber) override
        {
            this->filledSlot.erase(slotNumber);
        }

        int getNextSlot() override
        {
            //if(filledSlot.empty()==true)
            //    throw emptySlotException;
             return *(filledSlot.begin());
        }





};
#endif