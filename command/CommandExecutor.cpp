#ifndef COMMANDEXECUTOR
#define COMMANDEXECUTOR
#include "../Command.cpp"
#include "../ParkingLotManager.cpp"
#include "../OutputPrinter.cpp"
#include "../ParkingLot.cpp"
//#pragma once
class CommandExecutor
{
    protected:
        ParkingLotManager* parkingLotManager;
        OutputPrinter* outputPrinter;
    public:
        CommandExecutor(ParkingLotManager* parkingLotManager,OutputPrinter* outputPrinter)
        {
            this->parkingLotManager = parkingLotManager;
            this->outputPrinter = outputPrinter;
        }
        ~CommandExecutor(){}
        //virtual bool validate(Command* command) = 0;
        virtual void execute(Command* command) = 0;

};
#endif