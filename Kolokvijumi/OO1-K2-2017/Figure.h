#pragma once

#include "Polje.h"

#include <cctype>
#include <cmath>
#include <iostream>

enum class Boja {
	BELA,
	CRNA,
};

class Figura {
public:
	Figura(Boja boja, const Polje& polje)
		: boja_(boja), polje_(polje)
	{}

	virtual ~Figura() = default;

	virtual Figura* kloniraj() const = 0;

	virtual bool mozeSePomeriti(const Polje& p) const = 0;

	virtual bool mozePojesti(const Figura& f) const
	{
		return mozeSePomeriti(f.polje_) && boja_ != f.boja_;
	}

	void operator()(const Polje& p)
	{
		if (!mozeSePomeriti(p)) throw std::invalid_argument("Pomeranje nemoguce");
		polje_ = p;
	}

	Polje polje() const { return polje_; }

	virtual char oznaka()   const = 0;
	virtual int  vrednost() const = 0;

	bool operator>(const Figura& f) const { return vrednost() > f.vrednost(); }

	friend std::ostream& operator<<(std::ostream& os, const Figura& f)
	{
		char o = f.oznaka();
		return os << (char)((f.boja_ == Boja::BELA) ? std::toupper(o) : std::tolower(o));
	}

protected:
	const Boja boja_;
	Polje polje_;
};

class Top : public Figura {
public:
	using Figura::Figura; // Koristi postojeci ktor osnovne klase
	Top* kloniraj() const override { return new Top(*this); }
	bool mozeSePomeriti(const Polje& p) const override { return p + polje_; }
	char oznaka()   const override { return 'T'; }
	int  vrednost() const override { return 5; }
};

class Lovac : public Figura {
public:
	using Figura::Figura;
	Lovac* kloniraj() const override { return new Lovac(*this); }
	bool mozeSePomeriti(const Polje& p) const override { return p / polje_; }
	char oznaka()   const override { return 'L'; }
	int  vrednost() const override { return 3; }
};

class Skakac : public Figura {
public:
	using Figura::Figura;
	Skakac* kloniraj() const override { return new Skakac(*this); }

	bool mozeSePomeriti(const Polje& p) const override
	{
		return std::abs(p.red()-polje_.red()) == 1 && std::abs(p.kol()-polje_.kol()) == 2
			|| std::abs(p.red()-polje_.red()) == 2 && std::abs(p.kol()-polje_.kol()) == 1;
	}

	char oznaka()   const override { return 'S'; }
	int  vrednost() const override { return 2; }
};
