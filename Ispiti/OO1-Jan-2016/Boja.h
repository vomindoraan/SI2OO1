#ifndef _BOJA_H_
#define _BOJA_H_

#include <stdexcept>

class Boja {
public:
	using komp_t = unsigned;

	static const komp_t MIN = 0, MAX = 255;
	static const Boja CRNA, BELA;

	Boja(komp_t r, komp_t g, komp_t b)
		: r_(r), g_(g), b_(b)
	{
		if (r > MAX || g > MAX || b > MAX) {
			throw std::invalid_argument("komponenta boje nije u opsegu");
		}
	}

	friend bool operator==(const Boja& b1, const Boja& b2)
	{
		return b1.r_ == b2.r_ && b1.g_ == b2.g_ && b1.b_ == b2.b_;
	}

	komp_t r() const { return r_; }
	komp_t g() const { return g_; }
	komp_t b() const { return b_; }

private:
	komp_t r_, g_, b_;
};

#endif
