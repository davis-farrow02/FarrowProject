// code name: GPIO.cpp
// code by: Davis Farrow
//
// CPE 422 Project 1
// this code is the implementation of the GPIO class

#include "GPIO.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<fcntl.h>
#include<unistd.h>
#include<sys/epoll.h>
#include<pthread.h>
using namespace std;

GPIO::GPIO(int number) {
	this->number = number;

	ostringstream s;
	s << "gpio" << number;
	this->name = string(s.str());
	this->path = GPIO_PATH + this->name + "/";
	// this->exportGPIO();
	// need to give Linux time to set up the sysfs structure
	usleep(250000); // 250ms delay
}

int GPIO::write(string path, string filename, string value) {
	ofstream fs;
	fs.open((path + filename).c_str());
	if (!fs.is_open()){
		perror("GPIO: write failed to open file ");
		return -1;
	}
	fs << value;
	fs.close();
	return 0;
}

int GPIO::write(string path, string filename, int value) {
	stringstream s;
	s << value;
	return this->write(path,filename,s.str());
}

string GPIO::read(string path, string filename) {
	ifstream fs;
	fs.open((path + filename).c_str());
	if (!fs.is_open()){
		perror("GPIO: read failed to open file ");
	}
	string input;
	getline(fs,input);
	fs.close();
	return input;
}

int GPIO::getNumber() {
	return number;
}

int GPIO::setDirection(GPIO_DIRECTION dir) {
	switch(dir){
	case INPUT: return this->write(this->path, "direction", "in");
		break;
	case OUTPUT:return this->write(this->path, "direction", "out");
		break;
	}
	return -1;
}

GPIO_DIRECTION GPIO::getDirection() {
	string input = this->read(this->path, "direction");
	if (input == "in") return INPUT;
	else return OUTPUT;
}

int GPIO::setValue(GPIO_VALUE val) {
	switch(val){
		case HIGH: return this->write(this->path, "value", "1");
		break;
		case LOW: return this->write(this->path, "value", "0");
        	break;
	}
	return -1;
}

GPIO_VALUE GPIO::getValue() {
	string input = this->read(this->path, "value");
	if (input == "0") return LOW;
	else return HIGH;
}

void GPIO::toggleOutput() {
		this->setDirection(OUTPUT);
        	if ((bool) this->getValue()) this->setValue(LOW);
        	else this->setValue(HIGH);
	//return 0;
}

GPIO:: ~GPIO() {

}
