#include "Paket.h"

double Paket::vrednost() const
{
	double vr = 0;
	for (unsigned i = 0; i < zbirka_.duzina(); ++i) {
		vr += zbirka_[i]->vrednost();
	}
	return vr;
}

Roba* Paket::kopiraj() const
{
	return new Paket(*this);
}

void Paket::ispis(std::ostream& os) const
{
	os << '[';
	auto duz = zbirka_.duzina();
	for (unsigned i = 0; i < duz; ++i) {
		os << *zbirka_[i];
		if (i < duz-1) os << ',';
	}
	os << ']';
}
