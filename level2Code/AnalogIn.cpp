// code name: AnalogIn.cpp
// code by: Davis Farrow
//
// CPE 422 Project 1
// this code is the implementation of the AnalogIn class

#include<iostream>
#include<fstream>
#include<sstream>
#include "AnalogIn.h"
using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC 0

AnalogIn::AnalogIn() {
}

AnalogIn::AnalogIn(unsigned int n) {
	number = n;
}

void  AnalogIn::setNumber(unsigned int n) {
	number = n;
}

int AnalogIn::readAdc() {
	stringstream ss;
	ss << ADC_PATH << number << "_raw";
	fstream fs;
	fs.open(ss.str().c_str(), fstream::in);
	fs >> number;
	fs.close();
	return number;
}

AnalogIn::~AnalogIn() {
}
