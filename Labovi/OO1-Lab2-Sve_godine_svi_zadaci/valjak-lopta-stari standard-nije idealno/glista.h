#ifndef _glista_h_
#define _glista_h_

#include "telo.h"
#include <iostream>
using namespace std;

class Glista {
private:
	struct Elem {
		Telo *telo;
		Elem *sled;

		Elem(Telo *t) { telo = t; sled = 0; }
	};

	Elem *poc, *kraj;
	int broj;
	double tezina;

	void brisi() {
		Elem *pom = poc;
		while (poc != 0) {
			pom = poc;
			poc = poc->sled;
			delete pom->telo;
			delete pom;
		}
		poc = kraj = 0; broj = 0; tezina = 0;
	}

	void kopiraj(Glista &g) {
		broj = g.broj;
		tezina = g.tezina;
		Elem *pom = poc;
		while (pom != 0) {
			switch (pom->telo->dohvatiVrsta()) {
				case 'L' : g += new Lopta(((Lopta *)pom->telo)->dohvatiR(), pom->telo->dohvatiSigma());
					break;
				case 'V' : g += new Valjak(((Valjak *)pom->telo)->dohvatiR(), ((Valjak *)pom->telo)->dohvatiH(), pom->telo->dohvatiSigma());
					break;
			}
			pom = pom->sled;
		}
	}
public:
	Glista() { poc = kraj = 0; broj = 0; tezina = 0; }
	
	Glista(Glista &g) { kopiraj(g); }
	~Glista() { brisi(); }
	Glista &operator=(Glista &g) {
		if (this != &g) {
			brisi(); kopiraj(g);
		}
		return *this;
	}

	Glista &operator+=(Telo *t) {
		if (poc == 0) {
			poc = kraj = new Elem(t);
		} else {
			kraj->sled = new Elem(t);
			kraj = kraj->sled;
		}
		broj++;
		tezina += t->tezina();

		return *this;
	}

	double glistatezina() { return tezina; }

	friend ostream &operator<<(ostream &it, Glista &g) {
		Glista::Elem *pom = g.poc;
		while (pom != 0) {
			pom->telo->pisi(it);
			it << endl;
			pom = pom->sled;
		}
		return it;
	}

};

#endif