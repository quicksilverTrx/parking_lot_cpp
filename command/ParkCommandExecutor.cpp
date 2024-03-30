#ifndef PCE
#define PCE
#include <iostream>
#include <string>
#include "../OutputPrinter.cpp"
//#include "../Command.cpp"
#include "../ParkingLotManager.cpp"
#include "CommandExecutor.cpp"

class ParkCommandExecutor : public CommandExecutor 
{
    public:
    static std::string COMMAND_NAME;
    ParkCommandExecutor(ParkingLotManager* parkingLotManager,OutputPrinter* outputPrinter): CommandExecutor(parkingLotManager, outputPrinter) {}
    
    void execute(Command* command) override{
        Car* car = new Car(command->getParams()[0],command->getParams()[1]);

        int slot = parkingLotManager->park(car);
        outputPrinter->printWithNewLine("Allocated slot number: " + std::to_string(slot));
        

    }
};
std::string ParkCommandExecutor::COMMAND_NAME = "park";
#endif