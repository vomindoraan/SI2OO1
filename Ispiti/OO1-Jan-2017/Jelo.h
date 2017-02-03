#pragma once

#include "Lista.h"
#include "Sastojak.h"

#include <iostream>
#include <stdexcept>
#include <string>

class Jelo : private Lista<Sastojak*> { // Nasledjivanje umesto privatnog polja
public:
	Jelo(const string& ime) : ime_(ime), promena_(0), vreme_(-1) {}
	virtual ~Jelo();

	void promena(double proc) { promena_ = proc; }
	void vreme(int sat) { vreme_ = sat; }

	Jelo& dodaj(const Sastojak& s, int kol)
	{
		if (!adekvatan(s)) {
			throw invalid_argument("Sastojak nije adekvatan");
		}
		Lista::dodaj(s.kopiraj(), kol);
		return *this;
	}

	virtual char vrsta() const = 0;
	virtual double cena() const;

protected:
	int vreme_;
	double promena_;

	virtual bool adekvatan(const Sastojak& s) const { return true; }

private:
	string ime_;
};

class Predjelo : public Jelo {
public:
	using Jelo::Jelo;
	char vrsta() const override { return 'P'; }
	double cena() const override
	{
		if (vreme_ >= 9 && vreme_ <= 12) {
			return Jelo::cena() * (1 - promena_/100);
		}
		return Jelo::cena();
	}

protected:
	bool adekvatan(const Sastojak& s) const override
	{
		auto v = s.vrsta();
		return v == Sastojak::SLAN || v == Sastojak::NEUT;
	}
};

class GlavnoJelo : public Jelo {
public:
	using Jelo::Jelo;
	char vrsta() const override { return 'G'; }
	double cena() const override
	{
		if (vreme_ >= 20 && vreme_ <= 23) {
			return Jelo::cena() * (1 + promena_/100);
		}
		return Jelo::cena();
	}

protected:
	bool adekvatan(const Sastojak& s) const override
	{
		auto v = s.vrsta();
		return v == Sastojak::SLAN || v == Sastojak::NEUT;
	}
};

class Dezert : public Jelo {
public:
	using Jelo::Jelo;
	char vrsta() const override { return 'D'; }

protected:
	bool adekvatan(const Sastojak& s) const override
	{
		auto v = s.vrsta();
		return v == Sastojak::SLAD || v == Sastojak::NEUT;
	}
};
