#pragma once

#include <iostream>
#include <string>
using namespace std;

class Sastojak {
public:
	enum Vrsta { SLAN, SLAD, NEUT };

	Sastojak(const string& ime, double jedCena)
		: ime_(ime), jedCena_(jedCena)
	{}

	virtual ~Sastojak() {}

	virtual Vrsta vrsta() const = 0;
	virtual Sastojak* kopiraj() const = 0;

	double cena(double grami) const { return jedCena_ * grami / 1000; }

	friend ostream& operator<<(ostream& os, const Sastojak& s)
	{
		return os << s.ime_ << " - " << s.jedCena_ << "/kg";
	}

private:
	string ime_;
	double jedCena_;
};

class SlanSastojak : public Sastojak {
public:
	using Sastojak::Sastojak;
	Vrsta vrsta() const override { return SLAN; }
	Sastojak* kopiraj() const override { return new SlanSastojak(*this); }
};

class SladakSastojak : public Sastojak {
public:
	using Sastojak::Sastojak;
	Vrsta vrsta() const override { return SLAD; }
	Sastojak* kopiraj() const override { return new SladakSastojak(*this); }
};

class NeutralanSastojak : public Sastojak {
public:
	using Sastojak::Sastojak;
	Vrsta vrsta() const override { return NEUT; }
	Sastojak* kopiraj() const override { return new NeutralanSastojak(*this); }
};
