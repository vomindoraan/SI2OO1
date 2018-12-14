#include "otpornik.h"
#include "prost.h"
#include "slozen.h"
#include "redna.h"

double Redna::otpornost() const {
	double suma = 0;
	for (int i = 0; i<pop; i++)
		suma += pniz[i]->otpornost();
	return suma;
}

void Slozen::brisi() {
	if (pniz == nullptr) return;

	for (int i = 0; i<pop; i++)
		delete pniz[i];
	delete[] pniz;
}

void Slozen::kopiraj(const Slozen &s) {
	kap = s.kap;
	pop = s.pop;
	pniz = new Otpornik *[kap];
	for (int i = 0; i<pop; i++)
		pniz[i] = s.pniz[i]->kopija(); //zove polimorfno kopiranje objekta
}

void Slozen::pisi(ostream &it) const {
	it << "(";
	for (int i = 0; i<pop; i++) {
		if (i != 0) it << ",";
		it << *pniz[i];
	}
	it << ")";
}