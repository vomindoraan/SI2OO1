#include "Racun.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Uneti ime kupca i datum kupovine:" << endl;
	string kupac;
	long datum;
	cin >> kupac >> datum;

	Racun r(kupac, datum, 10);

	for (unsigned i = 0; i < 2; ++i) {
		cout << "Uneti stavku: ";
		string kupac;
		double cena;
		unsigned kol;
		cin >> kupac >> cena >> kol;

		Stavka s(kupac, cena, kol);
		r.dodajStavku(s);
	}

	cout << r << endl;

	return 0;
}
