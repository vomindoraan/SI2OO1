#ifndef ZBIRKAMT
#define ZBIRKAMT

#include "mernatacka.h"

#include <cstdlib>
#include <iostream>
using namespace std;

class ZbirkaMT {
	MernaTacka **pniz;
	int kap, pop;

	void brisi() {
		if (pniz == nullptr) return;
		for (int i=0; i<pop; i++)
			delete pniz[i];
		delete [] pniz;
	}

	void kopiraj(const ZbirkaMT &z) {
		kap = z.kap;
		pop = z.pop;
		pniz = new MernaTacka *[kap];
		for (int i=0; i<pop; i++)
			pniz[i] = new MernaTacka(*z.pniz[i]);
	}

	void premesti(ZbirkaMT &z) {
		kap = z.kap;
		pop = z.pop;
		pniz = z.pniz;
		z.pniz = nullptr;
	}
public:
	explicit ZbirkaMT(int kkap) {
		kap = kkap;
		pop = 0;
		pniz = new MernaTacka *[kap];
	}

	~ZbirkaMT() { brisi(); }

	ZbirkaMT(const ZbirkaMT &z) { kopiraj(z); }
	ZbirkaMT(ZbirkaMT &&z) { premesti(z); }
	ZbirkaMT &operator=(const ZbirkaMT &z) {
		if (this != &z) {
			brisi();
			kopiraj(z);
		}
		return *this;
	}
	ZbirkaMT &operator=(ZbirkaMT &&z) {
		if (this != &z) {
			brisi();
			premesti(z);
		}
		return *this;
	}

	ZbirkaMT &operator+=(const MernaTacka &mt) {
		if (kap==pop) exit(3);

		pniz[pop++] = new MernaTacka(mt);
		return *this;
	}

	int getKap() const { return kap; }
	int getPop() const { return pop; }

	double operator()(long t1, long t2) const {
		double suma = 0;

		for (int i=0; i<pop; i++)
			suma += pniz[i]->operator()(t1, t2); //suma += (*this)(t1, t2);

		if (pop==0) return 0;
		else return suma/pop;
	}
};

#endif