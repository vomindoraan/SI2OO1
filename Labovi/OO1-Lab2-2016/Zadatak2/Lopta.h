#pragma once

#include "Telo.h"

#include <iostream>

class Lopta : public Telo {
public:
	Lopta(double r, double tez) : Telo(tez, 'L') { r_ = r; }

	double v() const override { return 4/3 * r_*r_*r_ * PI; }

	Telo* kloniraj() const override { return new Lopta(*this); }

protected:
	void ispis(std::ostream& os) const override { os << r_; }

private:
	double r_;
};
