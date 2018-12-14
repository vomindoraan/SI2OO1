#include "vektor.h"
#include "izlomljena.h"
#include "mnogougao.h"

int main() {

	while (true) {
		cout << "Broj temena: ";
		int n;
		cin >> n;
	if (n <= 0) break;
		Mnogougao mn(n);

		for (int i=0; i<n; i++) {
			cout << "x, y, z: ";
			double x, y, z;
			cin >> x >> y >> z;
			mn += Vektor(x, y, z);
		}

		cout << mn << endl;

		cout << "Obim: " << mn.duzina() << endl;
	}
	return 0;
}