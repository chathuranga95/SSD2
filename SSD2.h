#ifndef SSD2_H
#define SSD2_H

#include "Arduino.h"

class SSD2{ 
public:
	SSD2(int A,int B,int C,int D,int E,int F_SEG,int G,int comc1, int comc2);
	void lightTwoDigits(int number,int dly);
	void lightDigit1(int digit);
	void lightDigit2(int digit);
	void lightSegments(int digit);
};

#endif