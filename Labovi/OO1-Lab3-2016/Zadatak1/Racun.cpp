#include "Racun.h"

double Racun::vrednost() const
{
	double vr = 0;
	for (unsigned i = 0; i < stavke_.duzina(); ++i) {
		vr += stavke_[i]->velicina();
	}
	return vr;
}
