#include "Filter.h"

void Filter::primeni(Galerija& g) const
{
	for (auto* p = g.prvi_; p != nullptr; p = p->sled) {
		auto& sl = p->pod;
		for (unsigned i = 0; i < sl.brVrsta(); ++i) {
			for (unsigned j = 0; j < sl.brKolona(); ++j) {
				obradi(sl(i, j));
			}
		}
	}
}
