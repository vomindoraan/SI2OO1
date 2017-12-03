#ifndef _IZLOMLJENA_H_
#define _IZLOMLJENA_H_

#include "vektor.h"

class Izlomljena {
private:
	//ne moze da se kopira
	Izlomljena(const Izlomljena &i) {}
	Izlomljena(Izlomljena &&i) {}
	void operator=(const Izlomljena &i) {}
	void operator=(Izlomljena &&i) {}
protected:
	Vektor *temena; //mozemo da pravimo niz vektora, jer Vektor ima podrazumevani konstruktor
	int kap, pop;

	virtual void pisi(ostream &it) const;
public:
	explicit Izlomljena(int kkap=3) {
		kap = kkap;
		pop = 0;
		temena = new Vektor[kap];
	}

	virtual ~Izlomljena() {} //u svakoj osnovnoj klasi pisemo virtuelni destruktor

	bool operator+=(const Vektor &v) {
		if (kap == pop) return false;
		temena[pop++] = v;
		return true;
	}

	int getKap() const { return kap; }

	virtual double duzina() const;

	//ovde nema polimorfnog kopiranja, jer ne moze da se kopira po specifikaciji zadatka

	friend ostream &operator<<(ostream &it, const Izlomljena &iz) {
		iz.pisi(it); //pravimo polimorfan ispis
		return it;
	}
};

#endif