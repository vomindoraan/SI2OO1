#ifndef _SLIKA_H_
#define _SLIKA_H_

#include "Element.h"
#include "PogresnaBoja.h"

#include <iostream>
#include <stdexcept>

class Slika {
public:
	Slika(unsigned vr = 3, unsigned kol = 4, const Boja& b = Boja::BELA);
	Slika(const Slika& s) { kopiraj(s); }
	Slika(Slika&& s) { premesti(s); }
	virtual ~Slika() { brisi(); }

	Slika& operator=(const Slika& s)
	{
		if (this != &s) {
			brisi();
			kopiraj(s);
		}
		return *this;
	}

	Slika& operator=(Slika&& s)
	{
		if (this != &s) {
			brisi();
			premesti(s);
		}
		return *this;
	}

	Element& operator()(unsigned i, unsigned j)
	{
		return mat_[i][j];
	}
	
	const Element& operator()(unsigned i, unsigned j) const
	{
		return const_cast<Slika&>(*this)(i, j);
	}

	void promeniBoju(unsigned i, unsigned j, const Boja& b) // nije virtual jer poziva provera(), a ona jeste
	{
		if (!provera(b)) {
			throw PogresnaBoja();
		}
		(*this)(i, j).boja(b);
	}

	unsigned brVrsta() const { return vr_; }
	unsigned brKolona() const { return kol_; }

	friend std::ostream& operator<<(std::ostream& os, const Slika& s)
	{
		s.pisi(os);
		for (unsigned i = 0; i < s.vr_; ++i) {
			os << std::endl;
			for (unsigned j = 0; j < s.kol_; ++j) {
				os << s(i, j) << ' ';
			}
		}
		return os;
	}

protected:
	virtual bool provera(const Boja& b) const { return true; }

	virtual void pisi(std::ostream& os) const { os << "Slika"; }

private:
	unsigned vr_, kol_;
	Element** mat_;

	void kopiraj(const Slika& s);
	void premesti(Slika& s);
	void brisi();
};

#endif // !_SLIKA_H_
