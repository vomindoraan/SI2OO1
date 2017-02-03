#ifndef _CRNO_BELA_SLIKA_H_
#define _CRNO_BELA_SLIKA_H_

#include "Slika.h"

class CrnoBelaSlika : public Slika {
public:
	using Slika::Slika;
	// koristi vec napisan ktor Slika(unsigned i = 3, unsigned j = 4, Boja b)
	// da ga ne bismo pisali opet za CrnoBelaSlika jer se ponasanje ne menja

protected:
	bool provera(const Boja& b) const override
	{
		return b == Boja::CRNA || b == Boja::BELA;
	}

	void pisi(std::ostream& os) const override { os << "Crno-bela slika"; }
};

#endif // !_CRNO_BELA_SLIKA_H_
