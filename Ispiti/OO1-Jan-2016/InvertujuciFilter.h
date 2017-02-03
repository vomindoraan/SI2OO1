#pragma once

#include "Filter.h"
#include "Boja.h"

class InvertujuciFilter : public Filter {
public:
	void obradi(Element& e) const override
	{
		auto stara = e.boja();
		Boja nova(Boja::MAX-stara.r(), Boja::MAX-stara.g(), Boja::MAX-stara.b());
		e.boja(nova);
	}
};
