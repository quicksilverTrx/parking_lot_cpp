#ifndef OUTPUTPRINTER
#define OUTPUTPRINTER
#include <iostream>
#include <string>
//#pragma once
class OutputPrinter {
public:
  void welcome() {
    printWithNewLine("Welcome to Go-Jek Parking lot.");
  }
  void end() {
    printWithNewLine("Thanks for using Go-Jek Parking lot service.");
  }
  void notFound() {
    printWithNewLine("Not found");
  }
  void statusHeader() {
    printWithNewLine("Slot No.    Registration No    Colour");
  }
  void parkingLotFull() {
    printWithNewLine("Sorry, parking lot is full");
  }
  void parkingLotEmpty() {
    printWithNewLine("Parking lot is empty");
  }
  void invalidFile() {
    printWithNewLine("Invalid file given.");
  }
  void printWithNewLine(const std::string& msg) {
    std::cout << msg << "\n";
  }
};
#endif

