#pragma once

#include "Telo.h"

#include <iostream>

class Valjak : public Telo {
public:
	Valjak(double r, double h, double tez) : Telo(tez, 'V') { r_ = r; h_ = h; }

	double v() const override { return r_*r_ * PI * h_ / 3; }

	Telo* kloniraj() const override { return new Valjak(*this); }

protected:
	void ispis(std::ostream& os) const override { os << r_ << ',' << h_; }

private:
	double r_, h_;
};
