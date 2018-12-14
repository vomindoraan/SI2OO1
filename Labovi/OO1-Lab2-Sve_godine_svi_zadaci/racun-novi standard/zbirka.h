#ifndef _ZBIRKA_H_
#define _ZBIRKA_H_

#include "predmet.h"

class Zbirka {
private:
	void brisi();

	void kopiraj(const Zbirka &z);

	void premesti(Zbirka &z) { //ovde prima referencu na l-vrednost, a salje se referenca na d-vrednost
		kap = z.kap;
		pop = z.pop;
		pniz = z.pniz;
		z.pniz = nullptr;
	}
protected:
	Predmet **pniz; //sadrzi pokazivace na predmete, jer predmet ne moze da postoji samostalno jer je apstraktna klasa
	int kap, pop;

	virtual void pisi(ostream &it) const;
public:
	explicit Zbirka(int kkap) {
		kap = kkap;
		pop = 0;
		pniz = new Predmet *[kap];
	}

	virtual ~Zbirka() { brisi(); }

	Zbirka(const Zbirka &z) { kopiraj(z); }

	Zbirka(Zbirka &&z) { premesti(z); }

	Zbirka &operator=(const Zbirka &z) {
		if (this != &z) {
			brisi();
			kopiraj(z);
		}
		return *this;
	}

	Zbirka &operator=(Zbirka &&z) {
		if (this != &z) {
			brisi();
			premesti(z);
		}
		return *this;
	}

	virtual Zbirka *kopija() const { return new Zbirka(*this); }

	bool operator+=(const Predmet &p) {
		if (kap == pop) return false;
		pniz[pop++] = p.kopija();
		return true;
	}

	double zbirVelicina() const;

	friend ostream &operator<<(ostream &it, const Zbirka &z) {
		z.pisi(it);
		return it;
	}
};

#endif