#ifndef ZKUPA
#define ZKUPA

#include "kupa.h"

#include <iostream>
using namespace std;

class ZKupa : public Kupa {
	void pisi(ostream &it) {
		it << r << "," << h << "," << d;
	}
protected:
	double d;
public:
	ZKupa(double rr=1, double hh=2, double dd=1) : Kupa(rr, hh) { d = dd; }

	double zapremina() { return r*r*3.14*(h*h*h-d*d*d)/3*h*h; }
};

#endif