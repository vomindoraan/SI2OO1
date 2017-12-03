#ifndef _AUTORIZOVANI_H_
#define _AUTORIZOVANI_H_

#include "dokument.h"

class Autorizovani : public Dokument {
protected:
	string potpis;

	void pisi(ostream &it) const {
		Dokument::pisi(it);		
		it << potpis;
	}
public:
	explicit Autorizovani(string pot, int kkap=5) : Dokument(kkap), potpis(pot) {}

	Autorizovani *kopija() const { return new Autorizovani(*this); }

	int duzina() const {
		return Dokument::duzina() + potpis.length();
	}
};

#endif