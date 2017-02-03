#include "Kupa.h"
#include "ZarubljenaKupa.h"
#include "Skladiste.h"

#include <iostream>

using namespace std;

int main()
{
	while (true) {
		Skladiste s;
		cout << "Uneti elemente skladista" << endl
			 << "k za Kupu, z za Zarubljenu Kupu, ostalo za kraj" << endl;

		bool vrti = true;
		while (vrti) {
			char c;
			cin >> c;

			double r, h, d;
			switch (c) {
			case 'k':
				cout << "r, h: ";
				cin >> r >> h;
				s += Kupa(r, h);
				break;
			case 'z':
				cout << "r, h, d: ";
				cin >> r >> h >> d;
				s += ZarubljenaKupa(r, h, d);
				break;
			default:
				vrti = false;
			}
		}

		double v1, v2;
		cout << "Uneti v1 i v2 (<0 za kraj): ";
		cin >> v1 >> v2;
		if (v1 < 0 || v2 < 0) {
			break;
		}

		cout << "Broj kupa je: " << s(v1, v2) << endl;
	}

	return 0;
}