#include "20161mnogougal.h"

void mnogougal::brisi()
{
	for (int i = 0; i < pop; i++) {
		delete niz[i];
		niz[i] = nullptr;
	}
	delete[] niz;
	pop = 0;
}

void mnogougal::kopiraj(const mnogougal & m)
{
	pop = m.pop;
	kap = m.kap;
	niz = new tacka*[m.kap];
	for (int i = 0; i < m.pop; i++) {
		niz[i] = m.niz[i]->klon();
	}
}

void mnogougal::premesti(mnogougal & m)
{
	pop = m.pop;
	kap = m.kap;
	niz = m.niz;
	m.niz = nullptr;
}
