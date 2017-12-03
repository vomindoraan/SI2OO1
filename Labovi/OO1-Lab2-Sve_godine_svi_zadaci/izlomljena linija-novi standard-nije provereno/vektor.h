#ifndef _VEKTOR_H_
#define _VEKTOR_H_

#include <cmath>

#include <iostream>
using namespace std;

class Vektor {
private:
	double x, y, z;
public:
	explicit Vektor(double xx=0, double yy=0, double zz=0) {
		x = xx; y = yy; z = zz;
	}

	friend Vektor operator+(const Vektor &v1, const Vektor &v2) {
		return Vektor(v1.x+v2.x, v1.y+v2.y, v1.z+v2.z);
	}

	friend Vektor operator-(const Vektor &v1, const Vektor &v2) {
		return Vektor(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
	}

	double operator~() const {
		return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	}

	friend ostream &operator<<(ostream &it, const Vektor &v) {
		return it << "(" << v.x << "," << v.y << "," << v.z << ")";
	}
};

#endif