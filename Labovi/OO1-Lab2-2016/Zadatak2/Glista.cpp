#include "Glista.h"

#include <cassert>

Glista & Glista::operator+=(const Telo & t)
{
	if (posl_ != nullptr && t.vrsta == posl_->telo->vrsta) {
		std::cerr << "Pogresan clanak " << t << std::endl;
		std::exit(1);
	}

	auto* e = new Elem(t.kloniraj());
	if (prvi_ == nullptr) {
		assert(posl_ == nullptr);
		prvi_ = e;
	} else {
		posl_->sled = e;
	}
	posl_ = e;

	return *this;
}

double Glista::tezina() const
{
	double res = 0;
	for (auto* e = prvi_; e != nullptr; e = e->sled) {
		res += e->telo->tez;
	}
	return res;
}

void Glista::kopiraj(const Glista & g)
{
	for (auto* e = g.prvi_; e != nullptr; e = e->sled) {
		*this += *e->telo;
	}
}

inline void Glista::premesti(Glista& g)
{
	prvi_ = g.prvi_;
	posl_ = g.posl_;
	g.prvi_ = g.posl_ = nullptr;
}

void Glista::brisi()
{
	while (prvi_ != nullptr) {
		auto* e = prvi_->sled;
		delete prvi_;
		prvi_ = e;
	}
}

std::ostream & operator<<(std::ostream & os, const Glista & g)
{
	os << '[';
	for (auto* e = g.prvi_; e != nullptr; e = e->sled) {
		os << *e->telo << ((e != g.posl_) ? '|' : ']');
	}
	return os;
}
