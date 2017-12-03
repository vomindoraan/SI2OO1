#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class kvadar {
protected:
	int a;
	int b;
	int c;
	void pisi(ostream &it) {
		it << "K ( " << a << ", " << b << ", " << c << " )";
	}
public:
	kvadar (int aa = 1, int bb = 1, int cc = 1) : a(aa), b(bb), c(cc) {}
	int zapremina() { return a*b*c; }
	friend ostream& operator<< (ostream& it, const kvadar &k) {
		k.pisi(it);
		return it;
	}
	friend bool operator==(const kvadar &k1, const kvadar &k2) {
		if (k2.a == k1.a && k2.b == k1.b && k2.c == k1.c)
			return true;
		else return false;
	}
	//virtual kvadar* klon(kvadar&k) { return new kvadar(*this); }
};