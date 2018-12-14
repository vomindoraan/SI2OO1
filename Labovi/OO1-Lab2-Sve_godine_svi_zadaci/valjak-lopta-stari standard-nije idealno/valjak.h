#ifndef _valjak_h_
#define _valjak_h_

#include "telo.h"
#include <iostream>
using namespace std;

class Valjak : public Telo {
private:
	double r, h;
public:
	Valjak(double rr, double hh, double ss) : Telo(ss, 'V') { r = rr; h = hh;}

	double zapremina() { return r*r*3.14*h; }

	double dohvatiR() { return r; }
	double dohvatiH() { return h; }

	void pisi(ostream &it) { Telo::pisi(it); it << r << "," << h; }
};

#endif