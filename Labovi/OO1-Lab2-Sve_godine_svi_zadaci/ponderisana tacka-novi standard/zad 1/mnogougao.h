#ifndef MNOGOUGAO
#define MNOGOUGAO

#include "tacka.h"
#include "ptacka.h"

#include <cstdlib>
#include <iostream>
using namespace std;

class Mnogougao {
	Tacka **pniz;
	int kap, pop;

	void brisi();

	void kopiraj(const Mnogougao &m);

	void premesti(Mnogougao &m) {
		kap = m.kap;
		pop = m.pop;
		pniz = m.pniz;
		m.pniz = nullptr;
	}
public:
	explicit Mnogougao(int kkap=3) {
		kap = kkap;
		pop = 0;
		pniz = new Tacka *[kap];
	}

	~Mnogougao() { brisi(); }
	Mnogougao(const Mnogougao &m) { kopiraj(m); }
	Mnogougao(Mnogougao &&m) { premesti(m); }
	Mnogougao &operator=(const Mnogougao &m) {
		if (this != &m) {
			brisi();
			kopiraj(m);
		}
		return *this;
	}
	Mnogougao &operator=(Mnogougao &&m) {
		if (this != &m) {
			brisi();
			premesti(m);
		}
		return *this;
	}

	//m+=pt -> m.operator+=(pt)
	Mnogougao &operator+=(const Tacka &pt) {
		if (kap == pop) exit(-1);

		pniz[pop++] = pt.kopija(); //dohvatam dinamicku kopiju poslate tacke
		return *this;
	}

	/*// m+=pt -> operator+=(m,pt)
	friend Mnogougao &operator+=(Mnogougao &m, const Tacka &pt) {
		if (m.kap == m.pop) exit(-1);
		m.pniz[m.pop++] = pt.kopija();
		return m;
	}*/

	int brojTemena() const { return pop; }

	const Tacka *najbliza() const;

	friend ostream &operator<<(ostream &it, const Mnogougao &m);
};

#endif
