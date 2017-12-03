#ifndef _ZBIRKA_H_
#define _ZBIRKA_H_

#include "dokument.h"
#include "autorizovani.h"

class Zbirka {
private:
	Dokument **pniz;
	int kap, pop;

	//zabranimo kopiranje
	Zbirka(const Zbirka &z) {}
	Zbirka(Zbirka &&z) {}
	void operator=(const Zbirka &z) {}
	void operator=(Zbirka &&z) {}
public:
	explicit Zbirka(int kkap) {
		kap = kkap;
		pop = 0;
		pniz = new Dokument *[kap];
	}

	~Zbirka();

	Zbirka &operator+=(const Dokument &d) {
		if (kap == pop) exit(7);
		pniz[pop++] = d.kopija(); //pozivam polimorfno kopiranje
		return *this;
	}

	int ukupnaDuzina() const;

	friend ostream &operator<<(ostream &it, const Zbirka &z);
};

#endif