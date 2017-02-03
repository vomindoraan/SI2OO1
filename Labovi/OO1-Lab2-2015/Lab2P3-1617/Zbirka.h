#ifndef _ZBIRKA_H_
#define _ZBIRKA_H_

#include "Merenje.h"
#include <cstdio>
#include <iostream>
#include <utility>

class Zbirka {
public:
	Zbirka(unsigned kap = 10) :
		kap_(kap), vel_(0),
		niz_(kap ? new Merenje[kap] : nullptr)
	{}

	Zbirka(const Zbirka& other) { kopiraj(other); }
	Zbirka(Zbirka&& other) { brisi(); premesti(std::move(other)); }
	~Zbirka() { brisi(); }

	Zbirka& operator=(const Zbirka& other)
	{
		if (this != &other) {
			brisi();
			kopiraj(other);
		}
		return *this;
	}

	Zbirka& operator=(Zbirka&& other)
	{
		if (this != &other) {
			brisi();
			premesti(std::move(other));
		}
		return *this;
	}

	Zbirka& operator+=(const Merenje& m);

	unsigned brMerenja() const { return vel_; }
	
	Merenje& operator[](unsigned i)
	{
		if (i >= vel_) {
			std::exit(1);
		}
		return niz_[i];
	}

	const Merenje& operator[](unsigned i) const
	{
		return const_cast<Zbirka&>(*this)[i];
	}

	double srTemp(double r, double x, double y);

	friend std::ostream& operator<<(std::ostream& os, const Zbirka& z);

private:
	unsigned kap_, vel_;
	Merenje* niz_;

	void kopiraj(const Zbirka& other);
	void premesti(Zbirka&& other);
	void brisi();
};

#endif
