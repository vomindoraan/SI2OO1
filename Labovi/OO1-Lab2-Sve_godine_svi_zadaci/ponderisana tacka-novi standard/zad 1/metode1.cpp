#include "mnogougao.h"
#include "ptacka.h"
#include "tacka.h"

void Mnogougao::brisi() {
	if (pniz == nullptr) return;
	for (int i = 0; i < pop; i++)
		delete pniz[i];
	delete[] pniz;
}

void Mnogougao::kopiraj(const Mnogougao &m) {
	kap = m.kap;
	pop = m.pop;
	pniz = new Tacka *[kap];
	for (int i = 0; i < pop; i++)
		pniz[i] = m.pniz[i]->kopija();
}

const Tacka *Mnogougao::najbliza() const {
	if (pop == 0) return nullptr; //ako nema nijedne tacke dodate, vracamo nula
	Tacka *min = pniz[0];
	for (int i = 0; i<pop; i++)
		if (pniz[i]->udaljenost() < min->udaljenost()) min = pniz[i];
	return min;
}

ostream &operator<<(ostream &it, const Mnogougao &m) {
	it << "[";
	for (int i = 0; i<m.pop; i++) {
		if (i != 0) it << "|";
		cout << *m.pniz[i];
	}
	it << "]" << endl;
	return it;
}