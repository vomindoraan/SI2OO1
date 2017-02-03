#include "Skladiste.h"

void Skladiste::brisi()
{
	while (prvi_ != nullptr) {
		auto* e = prvi_->sled;
		delete prvi_;
		prvi_ = e;
	}
	prvi_ = posl_ = nullptr;
}

unsigned Skladiste::operator()(double v1, double v2) const
{
	unsigned res = 0u;
	for (auto *e = prvi_; e != nullptr; e = e->sled) {
		auto v = e->kupa->v();
		if (v >= v1 && v < v2) {
			res++;
		}
	}
	return res;
}

std::ostream& operator<<(std::ostream& os, const Skladiste& s)
{
	os << '[';
	for (auto* e = s.prvi_; e != nullptr; e = e->sled) {
		os << *e->kupa << ((e != s.posl_) ? '|' : ']');
	}
	return os;
}
