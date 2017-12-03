#ifndef _SLOZEN_H_
#define _SLOZEN_H_

#include "otpornik.h"

class Slozen : public Otpornik {
private:
	void brisi();

	void kopiraj(const Slozen &s);

	void premesti(Slozen &s) {
		kap = s.kap;
		pop = s.pop;
		pniz = s.pniz;
		s.pniz = nullptr;
	}
protected:
	Otpornik **pniz;
	int kap, pop;

	virtual void pisi(ostream &it) const override;
public:
	explicit Slozen(int kkap=10) {
		kap = kkap;
		pop = 0;
		pniz = new Otpornik *[kap];
	}

	Slozen(const Slozen &s) { kopiraj(s); }

	Slozen(Slozen &&s) { premesti(s); }

	//posto je ovo klasa iz koje se dalje izvodi, ostavljam virtual destruktor
	virtual ~Slozen() override { brisi(); }

	Slozen &operator=(const Slozen &s) {
		if (this != &s) {
			brisi();
			kopiraj(s);
		}
		return *this;
	}

	Slozen &operator=(Slozen &&s) {
		if (this != &s) {
			brisi();
			premesti(s);
		}
		return *this;
	}

	bool operator+=(const Otpornik &o) {
		if (kap == pop) return false;
		pniz[pop++] = o.kopija(); //polimorfno kopiranje
		return true;
	}	

	//nismo redefinisali otpornost() i kopija(), pa ova klasa ostaje apstraktna
};

#endif