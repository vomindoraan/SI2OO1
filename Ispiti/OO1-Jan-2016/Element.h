#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include "Boja.h"

#include <iostream>

class Element {
public:
	Element(const Boja& boja = Boja::BELA)
		: boja_(boja)
	{}

	Boja boja() const { return boja_; }
	void boja(const Boja& val) { boja_ = val; }

	friend std::ostream& operator<<(std::ostream& os, const Element& e)
	{
		return os << '(' << e.boja_.r() << ',' << e.boja_.g() << ',' << e.boja_.b() << ')';
	}

private:
	Boja boja_;
};

#endif // !_ELEMENT_H_
