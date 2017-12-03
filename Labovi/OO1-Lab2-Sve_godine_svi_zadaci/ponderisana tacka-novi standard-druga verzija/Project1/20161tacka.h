#pragma once
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;
class tacka {
protected:
	virtual void pisi(ostream&it) {
		it << "( " << x << ", " << y << ", " << z << " )";
	}
	int x;
	int y;
	int z;
public:
	tacka(int a = 0, int b = 0, int c = 0) :x(a), y(b), z(c){}
	virtual double rastojanje() {
		return sqrt(x*x + y*y + z*z);
	}
	virtual tacka* klon() { return new tacka(*this); }
	friend ostream& operator<<(ostream&it, tacka& t) {
		t.pisi(it);
		return it;
	}
	virtual ~tacka(){}
};