#include <iostream>
#include <stdexcept>
#include "../OutputPrinter.cpp"
#include "../command/CommandExecutor.cpp"
#include "../command/CommandExecutorFactory.cpp"
//#include "../command/InvalidCommandException.cpp"
#include "../Command.cpp"

class BaseMode {
private:
  CommandExecutorFactory* commandExecutorFactory;
protected:
    OutputPrinter* outputPrinter;

public:
  BaseMode(CommandExecutorFactory* commandExecutorFactory, OutputPrinter* outputPrinter) {
    this->commandExecutorFactory = commandExecutorFactory;
    this->outputPrinter = outputPrinter;
  }

protected:
  void processCommand(Command* command) {
    CommandExecutor* commandExecutor = commandExecutorFactory->getCommandExecutor(command);
   //if (commandExecutor->validate(command)) {
      commandExecutor->execute(command);
    // } else {
    //   throw InvalidCommandException();
    // }
  }

public:
  virtual void process() =0;
  
};

