#pragma once

#include "Lista.h"
#include "Slika.h"

class Galerija : public Lista<Slika> {
	friend class Filter;
public:
	using Lista<Slika>::Lista; // Automatski dodaje delegirajuci ktor (: Lista<Slika>())
};
