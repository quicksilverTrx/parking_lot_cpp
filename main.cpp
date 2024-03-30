

#include "ParkingLotManager.cpp"
#include "ModeStrategy/FileMode.cpp"
#include "OutputPrinter.cpp"
#include "command/CommandExecutorFactory.cpp"
bool isFileInputMode(int argc, char* argv[]) {
  return *argv[1] == '2';
}

int main(int argc,char* argv[])
{
    ParkingLotManager parkingManager;
    OutputPrinter outputPrinter;
    CommandExecutorFactory commandExecutorFactory(&parkingManager);

    FileMode fileMode(&commandExecutorFactory, &outputPrinter,"file_input.txt");
    fileMode.process();


}


