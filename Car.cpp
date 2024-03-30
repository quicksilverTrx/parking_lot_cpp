#ifndef CAR
#define CAR
#include <string>
//#pragma once
class Car
{
    private:
        std::string uniqueID;
        std::string model;
    public:
        Car()
        {
            this->uniqueID = "";
            this->model = "";
        }
        Car ( std::string& uniqueID, std::string& model)
        {
            this->uniqueID = uniqueID;
            this->model = model;
        }
        std::string getUniqueID()
        {
            return this->uniqueID;
        }

        std::string getModel()
        {
            return this->model;
        }
};
#endif