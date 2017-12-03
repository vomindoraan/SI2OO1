#include "vektor.h"
#include "izlomljena.h"
#include "mnogougao.h"

//ovde sigurno treba izvuci "duze" metode (sa petljom ili vecim brojem naredbi)
//ali generalno mogu sve metoda da se definisu ovde

double Mnogougao::duzina() const {		
	if (pop == 0) return 0; //ako nije dodato nijedno teme
	double suma = Izlomljena::duzina();
	suma += ~(temena[0]-temena[pop-1]);//dodamo razliku prvog i poslednje temena
	return suma;
}

double Izlomljena::duzina() const {
	//kako se ovo radi, proveriti??
	double suma = 0;
	for (int i=0; i<pop-1; i++) 
		suma += ~(temena[i]-temena[i+1]);
	return suma;
}

void Izlomljena::pisi(ostream &it) const {
	it << "[";
	for (int i=0; i<pop; i++) {
		if (i != 0) it << ",";
		it << temena[i];
	}
	it << "]";
}