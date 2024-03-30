#ifndef ECE
#define ECE
#include <iostream>
#include <string>
#include "../OutputPrinter.cpp"
//#include "../Command.cpp"
#include "../ParkingLotManager.cpp"
#include "CommandExecutor.cpp"

class ExitCommandExecutor : public CommandExecutor {
public:
  static std::string COMMAND_NAME;
  ExitCommandExecutor(ParkingLotManager* parkingLotManager, OutputPrinter* outputPrinter)
    : CommandExecutor(parkingLotManager, outputPrinter) {}



  void execute(Command* command) override {
    outputPrinter->end();
  }
};

std::string ExitCommandExecutor::COMMAND_NAME = "exit";

#endif