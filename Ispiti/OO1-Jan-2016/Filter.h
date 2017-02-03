#pragma once

#include "Element.h"
#include "Galerija.h"

class Filter {
public:
	virtual void obradi(Element& e) const = 0;
	void primeni(Galerija& g) const;
};
