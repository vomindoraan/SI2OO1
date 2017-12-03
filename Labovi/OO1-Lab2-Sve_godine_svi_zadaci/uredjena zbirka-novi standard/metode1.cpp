#include "zbirka.h"
#include "uredjena.h"
#include "skup.h"

void Zbirka::kopiraj(const Zbirka &z) {
	kap = z.kap;
	pop = z.pop;
	korak = z.korak;
	pniz = new int[kap];
	for (int i=0; i<pop; i++)
		pniz[i] = z.pniz[i];
}

void Zbirka::pisi(ostream &it) const {
	it << "(";
	for (int i=0; i<pop; i++) {
		if (i != 0) it << ",";
		it << pniz[i];
	}
	it << ")";
}

//virtuelan, jer se redefinise u izvedenoj klasi
Zbirka &Zbirka::operator+=(int broj) {
	if (kap == pop) { //prosirenje kapaciteta za zadati korak
		kap += korak;
		int *temp = new int[kap]; //novi, veci niz
		for (int i=0; i<pop; i++)
			temp[i] = pniz[i]; //prekopiraj sve brojeve u novi niz
		delete [] pniz; //obrisi stari
		pniz = temp; //nakaci se na novi
	}
	pniz[pop++] = broj;
	return *this;
}

Uredjena &Uredjena::operator+=(int broj) {
	if (kap == pop) { //prosirenje kapaciteta za zadati korak
		kap += korak;
		int *temp = new int[kap]; //novi, veci niz
		for (int i=0; i<pop; i++)
			temp[i] = pniz[i]; //prekopiraj sve brojeve u novi niz
		delete [] pniz; //obrisi stari
		pniz = temp; //nakaci se na novi
	}
	//dodaje uredjeno
	int i;
	for (i=pop-1; i>=0 && pniz[i] > broj; i--) pniz[i+1] = pniz[i];
	pniz[i+1] = broj;
	pop++;
	return *this;
}

Skup &Skup::operator+=(int broj) {
	for (int i=0; i<pop; i++)
		if (pniz[i] == broj) return *this; //vraca se ako ga nadje
	Zbirka::operator+=(broj); //doda na kraj
	return *this;
}
