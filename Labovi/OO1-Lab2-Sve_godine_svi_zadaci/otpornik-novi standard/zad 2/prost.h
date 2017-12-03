#ifndef _PROST_H_
#define _PROST_H_

#include "otpornik.h"

//klasa Prost se javno izvodi iz klase Otpornik
class Prost : public Otpornik {
protected:
	double R;

	void pisi(ostream &it) const override { it << R; }
public:
	explicit Prost(double RR=1) : Otpornik() { R = RR; }
	
	double otpornost() const override { return R; }

	Prost *kopija() const override { return new Prost(*this); }
};

#endif