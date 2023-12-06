// code name: GPIO.h
// code by: Davis Farrow
//
// CPE 422 Project 1
// this code is the header file for class GPIO

#include<string>
#include<fstream>
using std::string;
using std::ofstream;

#define GPIO_PATH "/sys/class/gpio/"

enum GPIO_DIRECTION{ INPUT, OUTPUT };
enum GPIO_VALUE{ LOW=0, HIGH=1 };

class GPIO {
	private:
		int number;
		string name, path;
		int write(string path, string filename, string value);
		int write(string path, string filename, int value);
		string read(string path, string filename);
		ofstream stream;
	public:
		GPIO(int number); // constructor
		int getNumber();
		int setDirection(GPIO_DIRECTION dir);
		GPIO_DIRECTION getDirection();
		int setValue(GPIO_VALUE val);
		GPIO_VALUE getValue();
		void toggleOutput();
		~GPIO(); //deconstructor 
};
