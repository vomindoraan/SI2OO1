#pragma once

#include <iostream>

constexpr double PI = 3.14159265358979;

class Telo {
public:
	const double tez;
	const char vrsta;

	Telo(double tez, char vrsta) : tez(tez), vrsta(vrsta) {}

	virtual double v() const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Telo& t)
	{
		os << t.vrsta << '(';
		t.ispis(os);
		return os << ',' << t.tez << ')';
	}

	virtual Telo* kloniraj() const = 0;

protected:
	virtual void ispis(std::ostream& os) const = 0;
};