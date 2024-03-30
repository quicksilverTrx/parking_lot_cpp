#ifndef COMMAND
#define COMMAND
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
//#pragma once
class Command
{
    private:
        std::string commandName;
        std::vector<std::string> params;
    public:
    std::string getCommandName()
    {
        return commandName;
    }

    std::vector<std::string> getParams()
    {
        return params;
    }
    Command(const std::string& inputLine) {
        std::istringstream iss(inputLine);
        std::vector<std::string> tokensList;
        std::string temp;
        while(iss>>temp)
        {
            tokensList.push_back(temp);
        }
        commandName = tokensList[0];
        std::remove_if(commandName.begin(), commandName.end(), ::isspace);
        std::transform(commandName.begin(), commandName.end(), commandName.begin(), ::tolower);

        tokensList.erase(tokensList.begin());
        params = tokensList;
}
};
#endif