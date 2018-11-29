#pragma once

#include "Figure.h"

#include <iostream>
#include <utility>

class SahovskaTabla {
public:
	SahovskaTabla() {}
	SahovskaTabla(const SahovskaTabla& st);
	SahovskaTabla(SahovskaTabla&& st);
	~SahovskaTabla();

	SahovskaTabla& operator=(SahovskaTabla st)
	{
		swap(*this, st);
		return *this;
	}

	friend void swap(SahovskaTabla& st1, SahovskaTabla& st2);

	SahovskaTabla& operator+=(const Figura& f)
	{
		(*this)[f.polje()] = f.kloniraj();
		return *this;
	}

	bool operator()(const Polje& p1, const Polje& p2);

	Figura*& operator[](const Polje& p)
	{
		return figure_[p.red()][p.kol_idx()];
	}

	const Figura* operator[](const Polje& p) const
	{
		return const_cast<SahovskaTabla&>(*this)[p];
	}

	friend std::ostream& operator<<(std::ostream& os, const SahovskaTabla& st);

private:
	Figura* figure_[8][8] = { { 0 } };
};
