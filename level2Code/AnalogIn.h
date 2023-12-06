// code name: AnalogIn.h
// code by: Davis Farrow
//
// CPE 422 Project 1
// this code is the header file for class AnalogIn

class AnalogIn {
	private:
		unsigned int number;
	public:
		AnalogIn();
		AnalogIn(unsigned int n);
		virtual unsigned int getNumber() { return number; }
		virtual void setNumber(unsigned int n);
		virtual int readAdc();
		virtual ~AnalogIn();
};

