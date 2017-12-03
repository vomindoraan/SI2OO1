#ifndef _REDNA_H_
#define _REDNA_H_

#include "slozen.h"

/*Redosled pozivanja konstruktora:
1.konstruktor osnovne klase
2.konstruktori atributa klasnog tipa, redosledom navodjenja
3.konstruktor izvedene klase

Destruktori se pozivaju obrnutim redosledom.
*/

class Redna : public Slozen {
protected:
	void pisi(ostream &it) const override {
		it << "red";
		Slozen::pisi(it); //poziv metode pisi od osnovne klase, preko :: (pripadnosti)
	}
public:
	//posto slozen ima konstruktor, i redna mora da ima konstruktor
	explicit Redna(int kap=10) : Slozen(kap) {}

	double otpornost() const override;

	Redna *kopija() const override { return new Redna(*this); }
};

#endif