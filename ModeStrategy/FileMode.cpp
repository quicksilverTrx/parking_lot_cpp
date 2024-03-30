
#include <iostream>
#include <fstream>
#include <string>
#include "BaseMode.cpp"
class FileMode : public BaseMode
{
    private:
        std::string fileName;
    public:
        FileMode(CommandExecutorFactory* commandExecutorFactory, OutputPrinter* outputPrinter,std::string fileName): BaseMode(commandExecutorFactory,outputPrinter){
            this->fileName=fileName;
        }

        void process () override
        {
            std::ifstream file(fileName);
            if(!file.is_open())
            {
                outputPrinter->invalidFile();
                return;
            }
            std::string input;
            while (getline(file,input))
            {
                Command command(input);
                processCommand(&command);
            }
            file.close();
        }
};