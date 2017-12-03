#include "20161tacka.h"
#include "20161napuderisanaTacka.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "20161mnogougal.h"
using namespace std;
int main() {
	int kapp;
	int a, b, c, t, q;
	cout << "kap?" << endl;
	cin >> kapp;
	mnogougal mn(kapp);
	for (int i = 0; i < kapp; i++) {
		cout << "tacka = 1, napuderisana = 0?" << endl;
		cin >> t;
		cout << "kooredinate" << endl;
		cin >> a >> b >> c;
		if (t == 0) {
			cout << "koef?" << endl;
			cin >> q;
			mn += napuderisana(a, b, c, q);
		}
		else {
			mn += tacka(a, b, c);
		}
	}
	cout << mn;
}