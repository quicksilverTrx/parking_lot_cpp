#ifndef LCE
#define LCE
#include <iostream>
#include <string>
#include "../OutputPrinter.cpp"
//#include "../Command.cpp"
#include "../ParkingLotManager.cpp"
#include "CommandExecutor.cpp"
class LeaveCommandExecutor : public CommandExecutor 
{
    public:
    static std::string COMMAND_NAME;
    LeaveCommandExecutor(ParkingLotManager* parkingLotManager, OutputPrinter* outputPrinter):       CommandExecutor(parkingLotManager,outputPrinter){}
    
    void execute(Command* command) override{
        int slotNum = std::stoi(command->getParams()[0]);
        parkingLotManager->makeSlotFree(slotNum);
        outputPrinter->printWithNewLine("Slot number " + std::to_string(slotNum) + " is free");
    }
};
std::string LeaveCommandExecutor::COMMAND_NAME = "leave";
#endif