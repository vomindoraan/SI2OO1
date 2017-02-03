#pragma once

#include "Stavka.h"
#include "Zbirka.h"

#include <iostream>
#include <string>

class Racun {
public:
	Racun(std::string kupac, long datum, unsigned kap)
		: kupac_(kupac)
		, datum_(datum)
		, stavke_(kap)
	{}

	Racun& dodajStavku(Stavka& s) { stavke_ += &s; return *this; }

	double vrednost() const;

	friend std::ostream& operator<<(std::ostream& os, const Racun& r)
	{
		return os << r.kupac_ << ", "
			<< r.datum_ << ", "
			<< r.stavke_ << ", "
			<< r.vrednost();
	}

private:
	std::string kupac_;
	long datum_;
	Zbirka<Stavka> stavke_;
};