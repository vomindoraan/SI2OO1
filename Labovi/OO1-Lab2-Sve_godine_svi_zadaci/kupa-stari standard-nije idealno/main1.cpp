#include "kupa.h"
#include "zkupa.h"
#include "skladiste.h"

#include <iostream>
using namespace std;

void main() {
  while (1) {

	Skladiste skl;
	cout << "Koliko kupa? ";
	int n;
	cin >> n;
	if (n <= 0) break;

	int i, izbor;
	double r,h,d;
	Kupa *k;
	for (i=0; i<n; i++) {
		cout << "1. Kupa  2. Zarubljena kupa\n";
		cin >> izbor;
		cout << "r,h? ";
		cin >> r >> h;

		if (izbor == 1) k = new Kupa(r,h);
		else {
			cout << "d?";
			cin >> d;
			k = new ZKupa(r,h,d);
		}
		skl += k;
	}

	cout << skl << endl;

	double v1, v2;
	cout << "Zapremina v1, v2? ";
	cin >> v1 >> v2;

	cout << "Broj: " << skl(v1, v2) << endl;
  }
}