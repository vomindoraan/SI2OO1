#include "predmet.h"
#include "zbirka.h"
#include "stavka.h"
#include "racun.h"

int main() {
	Racun racun(5, "Aroma market", 21112014);

	racun += Stavka("Hleb", 40.5, 4);
	racun += Stavka("Mleko", 97.2, 10);
	racun += Stavka("Secer", 42.5, 5);

	cout << racun << endl;

	return 0;
}