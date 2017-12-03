#include "dokument.h"
#include "autorizovani.h"
#include "zbirka.h"

int Dokument::ukId = 0;

void Dokument::kopiraj(const Dokument &d) {
	kap = d.kap;
	pop = d.pop;
	pniz = new string[kap];
	for (int i=0; i<pop; i++)
		pniz[i] = d.pniz[i];
}

void Dokument::pisi(ostream &it) const {
	it << id << endl;
	for (int i=0; i<pop; i++)
		it << pniz[i] << endl << endl;
}

int Dokument::duzina() const {
	int suma = 0;
	for (int i=0; i<pop; i++)
		suma += pniz[i].length();
	return suma;
}

Zbirka::~Zbirka() {
	for (int i=0; i<pop; i++)
		delete pniz[i];
	delete [] pniz;
}

int Zbirka::ukupnaDuzina() const {
	int suma = 0;
	for (int i=0; i<pop; i++)
		suma += pniz[i]->duzina();
	return suma;
}

ostream &operator<<(ostream &it, const Zbirka &z) {
	for (int i=0; i<z.pop; i++) {
		it << *z.pniz[i] << endl;
		it << "**********" << endl;
	}
	return it;
}
