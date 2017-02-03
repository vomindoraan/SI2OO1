#include "Zbirka.h"

Zbirka& Zbirka::operator+=(const Merenje& m)
{
	if (vel_ == kap_) {
		auto st_kap = kap_;
		auto* tmp = new Merenje[kap_ += 5];
		for (unsigned i = 0; i < st_kap; ++i) {
			tmp[i] = niz_[i];
		}
		delete[] niz_;
		niz_ = tmp;
	}

	niz_[vel_++] = m;

	return *this;
}

double Zbirka::srTemp(double r = 1.0, double x = 0.0, double y = 0.0)
{
	double sum = 0;
	unsigned n = 0;
	Merenje m(0, x, y);

	for (unsigned i = 0; i < vel_; ++i) {
		//std::cout << "niz_[" << i << "] = " << niz_[i] << std::endl;
		if (niz_[i].dist(m) < r) {
			sum += niz_[i].temp();
		}
		n++;
	}

	return sum / n;
}

std::ostream& operator<<(std::ostream& os, const Zbirka& z)
{
	os << '{';
	for (unsigned i = 0; i < z.vel_; ++i) {
		os << z.niz_[i] << (i < z.vel_-1 ? ',' : '}');
	}
	return os;
}

void Zbirka::kopiraj(const Zbirka& other)
{
	kap_ = other.kap_;
	vel_ = other.vel_;
	niz_ = other.niz_ ? new Merenje[kap_] : nullptr;
	for (unsigned i = 0; i < vel_; ++i) {
		niz_[i] = other.niz_[i];
	}
}

void Zbirka::premesti(Zbirka&& other)
{
	kap_ = other.kap_;
	vel_ = other.vel_;
	niz_ = other.niz_;
	other.niz_ = nullptr;
}

void Zbirka::brisi()
{
	delete[] niz_;
	niz_ = nullptr;
}
