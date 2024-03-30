#ifndef CPLCE
#define CPLCE
#include <string>
#include "../OutputPrinter.cpp"
//#include "../Command.cpp"
#include "../ParkingLotManager.cpp"
#include "CommandExecutor.cpp"
#include "../ParkingStrategy/UserStrategy.cpp"
//#include "CommandExecutor.cpp"

class CreateParkingLotCommandExecutor : public CommandExecutor {
public:
    static std::string COMMAND_NAME;
    CreateParkingLotCommandExecutor(ParkingLotManager *parkingLotManager,OutputPrinter *outputPrinter): CommandExecutor(parkingLotManager, outputPrinter) {}
    
    void execute(Command* command) override {
        int parkingLotCapacity = stoi(command->getParams()[0]);
        ParkingLot parkingLot(parkingLotCapacity);
        parkingLotManager->createParkingLot(&parkingLot, new UserStrategy());
        outputPrinter->printWithNewLine("Created a parking lot with " + std::to_string(parkingLot.getCapacity()) + " slots");
    }
};

std::string CreateParkingLotCommandExecutor::COMMAND_NAME = "create_parking_lot";
#endif