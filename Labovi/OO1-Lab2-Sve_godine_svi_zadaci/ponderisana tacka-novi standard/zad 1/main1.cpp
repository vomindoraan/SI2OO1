#include "tacka.h"
#include "ptacka.h"
#include "mnogougao.h"

#include <iostream>
using namespace std;

void main() {
	while (true) {
		int n, izbor;
		cin >> n;
	if (n<=0) break;
		Mnogougao mn(n);

		Tacka *tp;

		double x,y,z,q;
		for (int i=0; i<n; i++) {
			cout << "1.Tacka  2.Ponderisana tacka ?";
			cin >> izbor;

			cout << "x,y,z?";
			cin >> x >> y >> z;
			if (izbor == 2) {
				cout << "q?"; 
				cin >> q; 
				mn += PTacka(x,y,z,q);
			} else 
				mn += Tacka(x,y,z);
		}

		cout << mn;

		cout << *mn.najbliza() << endl;
	}
}