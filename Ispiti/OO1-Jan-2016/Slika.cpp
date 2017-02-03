#include "Slika.h"
#include "PogresnaBoja.h"

#include <utility>

Slika::Slika(unsigned vr, unsigned kol, const Boja& b)
	: vr_(vr), kol_(kol)
{
	if (vr == 0 || kol == 0) {
		throw std::invalid_argument("br. vrsta ili kol. ne moze biti 0");
	} else if (!provera(b)) {
		throw PogresnaBoja(); // korisnicka klasa za gresku
	}

	mat_ = new Element*[vr];
	for (unsigned i = 0; i < vr; ++i) {
		mat_[i] = new Element[kol];
		for (unsigned j = 0; j < kol; ++j) {
			mat_[i][j].boja(b);
		}
	}
}

void Slika::kopiraj(const Slika& s)
{
	vr_ = s.vr_;
	kol_ = s.kol_;

	mat_ = new Element*[vr_];
	for (unsigned i = 0; i < vr_; ++i) {
		mat_[i] = new Element[kol_];
		for (unsigned j = 0; j < kol_; ++j) {
			mat_[i][j] = s.mat_[i][j];
		}
	}
}

void Slika::premesti(Slika& s)
{
	vr_ = s.vr_;
	kol_ = s.kol_;
	mat_ = std::exchange(s.mat_, nullptr);
}

void Slika::brisi()
{
	for (unsigned i = 0; i < vr_; ++i) {
		delete mat_[i];
	}
	delete mat_;
	mat_ = nullptr;
}
