#include "zbirka.h"
#include "uredjena.h"
#include "skup.h"

int main() {
	while (true) {

		cout << "Izaberi:  1. Zbirka  2. Uredjena zbirka  3. Skup  4. Kraj";
		int tip;
		cin >> tip;
	if (tip != 1 && tip != 2 && tip != 3) break;

		Zbirka *z = nullptr;

		int kap, korak;
		cout << "Kapacitet, korak: ";
		cin >> kap >> korak;
		switch (tip) {
			case 1: z = new Zbirka(kap, korak);
				break;
			case 2: z = new Uredjena(kap, korak);
				break;
			case 3: z = new Skup(kap, korak);
				break;
		}

		//dodajemo elemente
		while (true) {
			cout << "Unesi broj, 0 za kraj: ";
			int broj;
			cin >> broj;
		if (broj == 0) break;

			*z += broj;
		}

		cout << *z << endl;

		delete z;
	}
	return 0;
}