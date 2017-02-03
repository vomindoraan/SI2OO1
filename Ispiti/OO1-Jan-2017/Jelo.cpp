#include "Jelo.h"

Jelo::~Jelo()
{
	for (naPocetak(); postoji(); naSledeci()) {
		delete podatak();
	}
}

double Jelo::cena() const
{
	double cena = 0;
	for (naPocetak(); postoji(); naSledeci()) {
		cena += podatak()->cena(vrednost());
	}
	return cena;
}
