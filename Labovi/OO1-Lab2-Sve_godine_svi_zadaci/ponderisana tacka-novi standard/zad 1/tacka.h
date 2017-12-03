#ifndef TACKA
#define TACKA

#include <cmath>
#include <iostream>
using namespace std;

class Tacka {
protected:
	double x, y, z;

	//polimorfno pisanje
	virtual void pisi(ostream &it) const { 
		it << "(" << x << "," << y << "," << z << ")";
	}
public:
	explicit Tacka(double xx=0, double yy=0, double zz=0) {
		x = xx; y = yy; z = zz;
	}

	//uvek se u osnovnu klasu stavlja virtuelni destruktor
	virtual ~Tacka() {}

	//trazio je polimorfno kopiranje
	virtual Tacka *kopija() const { return new Tacka(*this); }

	virtual double udaljenost() const {
		return sqrt(x*x+y*y+z*z);
	}

	friend ostream &operator<<(ostream &it, const Tacka &t) {
		t.pisi(it);
		return it;
	}
};

#endif