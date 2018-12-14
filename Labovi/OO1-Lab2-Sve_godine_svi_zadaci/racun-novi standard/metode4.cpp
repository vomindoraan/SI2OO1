#include "predmet.h"
#include "zbirka.h"
#include "stavka.h"
#include "racun.h"

void Zbirka::brisi() {
	if (pniz == nullptr) return;

	for (int i=0; i<pop; i++)
		delete pniz[i];
	delete [] pniz;
}

void Zbirka::kopiraj(const Zbirka &z) {
	kap = z.kap;
	pop = z.pop;
	pniz = new Predmet *[kap];
	for (int i=0; i<pop; i++)
		pniz[i] = z.pniz[i]->kopija(); //poziva polimorfno kopiranje
}

void Zbirka::pisi(ostream &it) const {
	for (int i=0; i<pop; i++)
		it << *pniz[i] << endl;
}

double Zbirka::zbirVelicina() const {
	double suma = 0;
	for (int i=0; i<pop; i++)
		suma += pniz[i]->velicina();
	return suma;
}

void Racun::pisi(ostream &it) const {
	it << ime << " " << datum << endl;
	Zbirka::pisi(it); //spisak stavki
	it << endl << zbirVelicina() << endl;
}