#include "dokument.h"
#include "autorizovani.h"
#include "zbirka.h"

int main() {
	while (true) {
		cout << "Kapacitet (negativan za kraj): ";
		int kap;
		cin >> kap;
	if (kap <=0) break;

		Zbirka zbirka(kap);

		int tip;
		string potpis;
		int k;
		while (true) {
			cout << "0.Kraj  1.Dokument  2.Autorizovani dokument: ";
			cin >> tip;
		if (tip != 1 && tip != 2) break;

			cout << "Kapacitet: ";
			cin >> k;
			getchar();

			if (tip == 2) { cout << "Potpis: "; getline(cin, potpis); }

			Dokument *d = nullptr;
			if (tip == 1)
				d = new Dokument(k);
			else
				d = new Autorizovani(potpis, k);

			cout << "Unesi " << k << " pasusa: ";
			string pasus;
			for (int j=0; j<k; j++) {
				getline(cin, pasus);
				*d += pasus;
			}

			zbirka += *d;
			delete d;
		}

		cout << zbirka << endl;
		cout << "Ukupna duzina: " << zbirka.ukupnaDuzina() << endl;
	}
	return 0;
}