#ifndef _ZARUBLJENA_KUPA_H_
#define _ZARUBLJENA_KUPA_H_

#include "Kupa.h"

#include <iostream>

class ZarubljenaKupa : public Kupa {
public:
	ZarubljenaKupa(double r, double h, double d = 1.0) :
		Kupa(r, h)
	{
		d_ = d;
	}

	double v() const override { return r_*r_ * PI * (h_*h_*h_ - d_*d_*d_) / (3*h_); }

	Kupa* kloniraj() const override { return new ZarubljenaKupa(*this); }

protected:
	void ispis(std::ostream& os) const override
	{
		Kupa::ispis(os);
		os << ',' << d_;
	}

private:
	double d_;
};

#endif // !_ZARUBLJENA_KUPA_H_
