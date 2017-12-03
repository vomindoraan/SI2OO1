#ifndef _RACUN_H_
#define _RACUN_H_

#include "zbirka.h"
#include "predmet.h"
#include "stavka.h"

class Racun : public Zbirka {
protected:
	string ime;
	long datum;

	void pisi(ostream &it) const;
public:
	Racun(int kkap, const string &im, long dat) : Zbirka(kkap), ime(im) { datum = dat; }

	Racun *kopija() const { return new Racun(*this); }
};

#endif