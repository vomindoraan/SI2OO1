#ifndef MERENJE
#define MERENJE

#include <iostream>
using namespace std;

class Merenje {
protected:
	double temp;
	long vreme;
public:
	Merenje(double ttemp, long vvreme) {
		temp = ttemp;
		vreme = vvreme;
	}

	double getTemp() const { return temp; }
	long getVreme() const { return vreme; }
};

#endif