#ifndef _SIVA_SLIKA_H_
#define _SIVA_SLIKA_H_

#include "Slika.h"

class SivaSlika : public Slika {
public:
	using Slika::Slika;

protected:
	bool provera(const Boja& b) const override
	{
		return b.r() == b.g() && b.g() == b.b();
	}
	
	void pisi(std::ostream& os) const override { os << "Slika u nijansi sive"; }
};

#endif // !_SIVA_SLIKA_H_
