#pragma once

#include "Element.h"

#include <iostream>
#include <string>

class Stavka : public Element {
public:
	Stavka(std::string naziv, double cena, unsigned kol)
		: naziv_(naziv)
		, cena_(cena)
		, kol_(kol)
	{}

	double velicina() const override
	{
		return cena_ * kol_;
	}

	friend std::ostream& operator<<(std::ostream& os, const Stavka& s)
	{
		return os << s.naziv_ << '('
			<< s.cena_ << ','
			<< s.kol_ << ','
			<< s.velicina() << ')';
	}

private:
	std::string naziv_;
	double cena_;
	unsigned kol_;
};
