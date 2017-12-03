#ifndef _lopta_h_
#define _lopta_h_

#include "telo.h"
#include <iostream>
using namespace std;

class Lopta : public Telo {
private:
	double r;
public:
	Lopta(double rr, double ss) : Telo(ss, 'L') { r = rr; }

	double zapremina() { return 4.0/3*r*r*r*3.14; }

	double dohvatiR() { return r; }

	void pisi(ostream &it) { Telo::pisi(it); it << r; }
};

#endif