#pragma once
#include "20161tacka.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;
class napuderisana : public tacka {
protected:
	int q;
	virtual void pisi(ostream& it) {
		tacka::pisi(it);
		it << " * " << q;
	}
public:
	napuderisana(int xx, int yy, int zz, int qq) : tacka(xx, yy, zz), q(qq){}
	double rastojanje() override {
		double pera = tacka::rastojanje();
		pera = pera * q;
		return pera;
	}
	virtual napuderisana* klon() { return new napuderisana(*this); }
};