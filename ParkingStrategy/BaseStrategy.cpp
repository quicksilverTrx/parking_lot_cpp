//#pragma once
#ifndef BASESTRATEGY
#define BASESTRATEGY
class BaseStrategy
{
    public:

        virtual void addSlot (int slotNumber)=0;
        virtual void removeSlot (int slotNumber)=0;
        virtual int getNextSlot ()=0;
};
#endif

