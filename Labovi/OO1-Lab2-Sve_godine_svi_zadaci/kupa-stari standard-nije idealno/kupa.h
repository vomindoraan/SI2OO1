#ifndef KUPA
#define KUPA

#include <iostream>
using namespace std;

class Kupa {
	virtual void pisi(ostream &it) {
		it << r << "," << h;
	}
protected:
	double r, h;
public:
	Kupa(double rr=1, double hh=2) {
		r = rr; h = hh;
	}

	virtual double zapremina() { return r*r*3.14*h/3; }

	bool operator<(Kupa &k) {
		return zapremina() < k.zapremina();
	}

	friend ostream &operator<<(ostream &it, Kupa &k) {
		k.pisi(it);
		return it;
	}
};

#endif