#ifndef CEF
#define CEF
#include <unordered_map>

//#pragma once
#include "CommandExecutor.cpp"
#include "ParkCommandExecutor.cpp"
#include "ExitCommandExecutor.cpp"
#include "LeaveCommandExecutor.cpp"
#include "CreateParkingLotCommandExecutor.cpp"

#include "../ParkingLotManager.cpp"
class CommandExecutorFactory{
    private:
        std::unordered_map<std::string,CommandExecutor*> commands;
    public:
        CommandExecutorFactory(ParkingLotManager* parkingLotManager)
        {
            OutputPrinter* outputPrinter = new OutputPrinter();
            commands[CreateParkingLotCommandExecutor::COMMAND_NAME] = new CreateParkingLotCommandExecutor(parkingLotManager, outputPrinter);
            commands[ParkCommandExecutor::COMMAND_NAME] = new ParkCommandExecutor(parkingLotManager, outputPrinter);
            commands[LeaveCommandExecutor::COMMAND_NAME] = new LeaveCommandExecutor(parkingLotManager, outputPrinter);
            //commands[StatusCommandExecutor::COMMAND_NAME] = new StatusCommandExecutor(parkingLotService, outputPrinter);
           // commands[ModelToIDCommandExecutor::COMMAND_NAME] = new ModelToIDCommandExecutor(parkingLotService, outputPrinter);
           // commands[ModelToSlotNumberCommandExecutor::COMMAND_NAME] = new ModelToSlotNumberCommandExecutor(parkingLotService, outputPrinter);
            //commands[SlotForIDCommandExecutor::COMMAND_NAME] = new SlotForIDCommandExecutor(parkingLotService, outputPrinter);
            commands[ExitCommandExecutor::COMMAND_NAME] = new ExitCommandExecutor(parkingLotManager, outputPrinter);
        }

        CommandExecutor* getCommandExecutor(Command* command)
        {
            CommandExecutor* commandExecutor = commands[command->getCommandName()];

            return commandExecutor;
        }


};
#endif