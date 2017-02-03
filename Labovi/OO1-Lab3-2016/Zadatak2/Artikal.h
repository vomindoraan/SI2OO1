#pragma once

#include "Roba.h"

class Artikal : public Roba {
public:
	Artikal(char oznaka = '?', double vrednost = 0)
		: ozn_(oznaka)
		, vr_(vrednost)
	{}

	char oznaka() const { return ozn_; }

	double vrednost() const override { return vr_; }

	Roba* kopiraj() const override { return new Artikal(*this); }

protected:
	void ispis(std::ostream& os) const override { os << ozn_; }

private:
	char ozn_;
	double vr_;
};