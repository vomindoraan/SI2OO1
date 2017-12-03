#ifndef _PREDMET_H_
#define _PREDMET_H_

#include <iostream>
using namespace std;

class Predmet {
protected:
	virtual void pisi(ostream &it) const = 0; //apstraktno
public:
	virtual ~Predmet() {} //uvek ostavljamo u osnovnoj klasi

	virtual double velicina() const = 0; //apstraktno

	virtual Predmet *kopija() const = 0; //apstraktno (polimorfno) kopiranje

	friend ostream &operator<<(ostream &it, const Predmet &p) {
		p.pisi(it);
		return it;
	}
};

#endif