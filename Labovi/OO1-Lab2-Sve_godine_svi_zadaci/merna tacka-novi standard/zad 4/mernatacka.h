#ifndef MERNATACKA
#define MERNATACKA

#include "tacka.h"
#include "merenje.h"

#include <cstdlib>
#include <iostream>
using namespace std;

class MernaTacka : public Tacka {
protected:
	Merenje **pniz;
	int kap, pop;

	void brisi() {
		if (pniz == nullptr) return;
		for (int i=0; i<pop; i++)
			delete pniz[i];
		delete [] pniz;
	}

	void kopiraj(const MernaTacka &mt) {
		kap = mt.kap;
		pop = mt.pop;
		pniz = new Merenje *[kap];
		for (int i = 0; i < pop; i++)
			pniz[i] = new Merenje(*mt.pniz[i]);
	}

	void premesti(MernaTacka &mt) {
		kap = mt.kap;
		pop = mt.pop;
		pniz = mt.pniz;
		mt.pniz = nullptr;
	}
public:
	explicit MernaTacka(int kkap, double xx=0, double yy=0, double zz=0) : Tacka(xx, yy, zz) {
		kap = kkap;
		pop = 0;
		pniz = new Merenje *[kap];
	}

	~MernaTacka() override { brisi(); }

	MernaTacka(const MernaTacka &mt) { kopiraj(mt); }
	MernaTacka(MernaTacka &&mt) { premesti(mt); }
	MernaTacka &operator=(const MernaTacka &mt) {
		if (this != &mt) {
			brisi();
			kopiraj(mt);
		}
		return *this;
	}
	MernaTacka &operator=(MernaTacka &&mt) {
		if (this != &mt) {
			brisi();
			premesti(mt);
		}
		return *this;
	}

	MernaTacka *kopija() const override { return new MernaTacka(*this); }

	MernaTacka &operator+=(const Merenje &mer) {
		if (kap == pop) exit(10);

		pniz[pop++] = new Merenje(mer);
		return *this;
	}

	Merenje &operator[](int indeks) { //pristup merenju
		if (indeks < 0 || indeks > pop-1) exit(23);
		return *pniz[indeks];
	}

	const Merenje &operator[](int indeks) const { //pristup merenju za konstantan objekat
		if (indeks < 0 || indeks > pop - 1) exit(23);
		return *pniz[indeks];
	}

	double operator()(long t1, long t2) const {
		double suma = 0;
		int n = 0;
		for (int i=0; i<pop; i++)
			if (pniz[i]->getVreme() > t1 && pniz[i]->getVreme() < t2) {
				suma += pniz[i]->getTemp();
				n++;
			}
		if (n==0) return 0;
		else return suma/n;
	}
};

#endif