#ifndef _MNOGOUGAO_H_
#define _MNOGOUGAO_H_

#include "izlomljena.h"

class Mnogougao : public Izlomljena {
private:
	//posto osnovna klasa ne moze da se kopira, ne moze ni izvedena posto sadrzi objekat osnovne
	Mnogougao(const Mnogougao &m) {}
	Mnogougao(Mnogougao &&m) {}
	void operator=(const Mnogougao &m) {}
	void operator=(Mnogougao &&m) {}
protected:
	void pisi(ostream &it) const {
		it << "M";
		Izlomljena::pisi(it);
	}
public:
	explicit Mnogougao(int kkap=3) : Izlomljena(kkap) {}

	double duzina() const;
};

#endif