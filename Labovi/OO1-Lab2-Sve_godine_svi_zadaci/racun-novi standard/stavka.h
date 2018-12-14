#ifndef _STAVKA_H_
#define _STAVKA_H_

#include <string>

#include "predmet.h"

class Stavka : public Predmet {
protected:
	string naziv;
	double jedcena, kol;

	void pisi(ostream &it) const {
		it << naziv << "/" << kol << "," << jedcena; //ovo nije rekao kako da se pise
	}
public:
	Stavka(const string &naz, double jc, double k) : naziv(naz) {
		jedcena = jc; kol = k;
	}
	
	double velicina() const { return kol*jedcena; }

	Stavka *kopija() const { return new Stavka(*this); }
};

#endif