#ifndef _KUPA_H_
#define _KUPA_H_

#include <iostream>

constexpr double PI = 3.14159265358979;

class Kupa {
public:
	explicit Kupa(double r = 1.0, double h = 2.0) :
		r_(r), h_(h)
	{}

	virtual double v() const { return r_*r_ * PI * h_ / 3; }

	bool operator<(const Kupa& k) { return v() < k.v(); }

	friend std::ostream& operator<<(std::ostream& os, const Kupa& k)
	{
		k.ispis(os);
		return os;
	}

	virtual Kupa* kloniraj() const { return new Kupa(*this); }

protected:
	virtual void ispis(std::ostream& os) const { os << r_ << ',' << h_; }

	double r_, h_;
};

#endif // !_KUPA_H_
