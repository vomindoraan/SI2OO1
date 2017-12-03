#ifndef PTACKA
#define PTACKA

#include "tacka.h"
#include <iostream>
using namespace std;

class PTacka : public Tacka {
protected:
	double q;

	void pisi(ostream &it) const override {
		Tacka::pisi(it); //prvo zovem pisi od roditelja
		it << "*" << q;
	}
public:
	//prvo se poziva konstruktor osnovne klase, pa konstruktori atributa klasnog tipa, pa konstruktor izvedene klase
	explicit PTacka(double xx=0, double yy=0, double zz=0, double qq=1) : Tacka(xx, yy, zz) { q = qq; }

	double udaljenost() const override { return Tacka::udaljenost()*q; }

	PTacka *kopija() const override { return new PTacka(*this); }
};

#endif