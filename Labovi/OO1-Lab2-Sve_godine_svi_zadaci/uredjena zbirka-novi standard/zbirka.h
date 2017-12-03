#ifndef _ZBIRKA_H_
#define _ZBIRKA_H_

#include <iostream>
using namespace std;

class Zbirka {
private:
	void brisi() { 
		if (pniz == nullptr) return;
		delete [] pniz; 
	}

	void kopiraj(const Zbirka &z);

	void premesti(Zbirka &z) {
		kap = z.kap;
		pop = z.pop;
		korak = z.korak;
		pniz = z.pniz;
		z.pniz = nullptr;
	}
protected:
	int *pniz;
	int kap, pop, korak;

	virtual void pisi(ostream &it) const;
public:
	explicit Zbirka(int kkap=10, int kor=4) {
		kap = kkap;
		pop = 0;
		korak = kor;
		pniz = new int[kap];
	}

	Zbirka(const Zbirka &z) { kopiraj(z); }

	Zbirka(Zbirka &&z) { premesti(z); }

	virtual ~Zbirka() { brisi(); }

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

	//virtuelan, jer se redefinise u izvedenoj klasi
	virtual Zbirka &operator+=(int broj);

	virtual Zbirka *kopija() const { return new Zbirka(*this); } //polimorfno kopiranje

	int getPop() const { return pop; }

	const int &operator[](int indeks) const { //moze i samo da vrati int
		if (indeks<0 || indeks>pop-1) exit(5);
		return pniz[indeks];
	}

	friend ostream &operator<<(ostream &it, const Zbirka &z) {
		z.pisi(it);
		return it;
	}
};

#endif