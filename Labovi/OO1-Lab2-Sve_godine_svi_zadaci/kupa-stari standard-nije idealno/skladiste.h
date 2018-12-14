#ifndef SKLADISTE
#define SKLADISTE
#include "kupa.h"

struct Elem {
	Kupa *sk;
	Elem *sled;

	Elem(Kupa *skl) {
		sk = skl;
		sled = 0;
	}
};

class Skladiste {
	Elem *prvi, *posl;

	void brisi() {
		Elem *stari;
		while (prvi) {
			stari = prvi;
			prvi = prvi->sled;
			delete stari->sk;
			delete stari;
		}
	}

	Skladiste(Skladiste &s) {}
	Skladiste &operator=(Skladiste &s) { return *this; }
public:
	Skladiste() { prvi = posl = 0; }

	~Skladiste() { brisi(); }

	Skladiste &operator+=(Kupa *k) {
		Elem *novi = new Elem(k);

		if (prvi == 0) 
			prvi = posl = novi;
		else {
			posl->sled = novi;
			posl = novi;
		}
		return *this;
	}

	int operator()(double v1, double v2) {
		int broj = 0;
		for (Elem *tek=prvi; tek; tek=tek->sled)
			if ((tek->sk->zapremina() > v1) && (tek->sk->zapremina() < v2)) broj++;
		return broj;
	}

	friend ostream &operator<<(ostream &it, Skladiste &s) {
		it << "[";
		for (Elem *tek=s.prvi; tek!=s.posl; tek=tek->sled)
			it << *tek->sk << "|";
		it << *s.posl->sk << "]" << endl;
		return it;
	}
};

#endif