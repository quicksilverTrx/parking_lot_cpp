//#pragma once
#ifndef EXCEPTION
#define EXCEPTION
#include <stdexcept>
#include <string>
class ParkingLotException : public std::runtime_error {
public:
    ParkingLotException() : std::runtime_error("") {}
    ParkingLotException(const std::string& message) : std::runtime_error(message) {}
};

class SlotAlreadyOccupiedException : public ParkingLotException {};

class InvalidSlotException : public ParkingLotException {};
#endif