#ifndef _kvadar_h_
#define _kvadar_h_

#include <iostream>
using namespace std;

class Kvadar {
private: 
	double a,b,c;
public: 
	explicit Kvadar(double prva=1,double druga=1,double treca=1) {
		a=prva; b=druga;c=treca;
	}

	double zapremina() const { return a*b*c; }

	friend bool operator==(const Kvadar &prvi, const Kvadar &drugi){
		return prvi.a==drugi.a && prvi.b==drugi.b && prvi.c==drugi.c;
	}

	friend ostream& operator<<(ostream &it, const Kvadar &k){
		it<<"K("<<k.a<<","<<k.b<<","<<k.c<<")"; 
		return it;
	}
};

#endif

