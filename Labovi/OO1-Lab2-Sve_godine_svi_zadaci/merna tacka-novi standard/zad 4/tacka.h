#ifndef TACKA
#define TACKA

#include <iostream>
#include <cmath>
using namespace std;

class Tacka {
protected:
	double x, y, z;

	virtual void pisi(ostream &it) const { it << "(" << x << "," << y << "," << z << ")"; }
public:
	explicit Tacka(double xx=0, double yy=0, double zz=0) {
		x = xx; y = yy; z = zz;
	}

	virtual ~Tacka() {}

	virtual Tacka *kopija() const { return new Tacka(*this); }

	friend double operator-(const Tacka &t1, const Tacka &t2) {
		return sqrt(pow(t1.x-t2.x, 2) + pow(t1.y-t2.y, 2) + pow(t1.z-t2.z, 2));
	}

	friend ostream &operator<<(ostream &it, const Tacka &t) {
		t.pisi(it);
		return it;
	}
};

#endif