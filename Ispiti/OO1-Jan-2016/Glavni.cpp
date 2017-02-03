#include "Boja.h"
#include "Slika.h"
#include "Galerija.h"
#include "InvertujuciFilter.h"

#include <algorithm>
#include <exception>

using namespace std;

int main()
{
	try {
		Slika s1, s2(16, 16, Boja(255, 0, 0)), s3(s1), s4(30, 30, Boja::CRNA);

		for (unsigned i = 0; i < min(s1.brVrsta(), s1.brKolona()); ++i) {
			s1(i, i).boja(Boja(192, 0, 192));
		}

		Galerija g;
		g.dodaj(s1).dodaj(s2).dodaj(s3).dodaj(s4);
		cout << g;

		InvertujuciFilter f;
		f.primeni(g);
		cout << g;
	} catch (const exception& e) { // Treba samo jedan catch umesto nekoliko
		cout << e.what();
	}

	return 0;
}
