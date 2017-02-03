#pragma once

#include "Telo.h"

#include <iostream>
#include <cstdlib>

class Glista {
public:
	Glista() : prvi_(nullptr), posl_(nullptr) {}
	Glista(const Glista& g) { kopiraj(g); }
	Glista(Glista&& g) { premesti(g); }
	~Glista() { brisi(); }

	Glista& operator=(const Glista& g)
	{
		if (this != &g) {
			brisi();
			kopiraj(g);
		}
		return *this;
	}

	Glista& operator=(Glista&& g)
	{
		if (this != &g) {
			brisi();
			premesti(g);
		}
		return *this;
	}

	Glista& operator+=(const Telo& t);

	double tezina() const;

	friend std::ostream& operator<<(std::ostream& os, const Glista& g);

private:
	struct Elem {
		Telo* telo;
		Elem* sled;
		Elem(Telo* telo, Elem* sled = nullptr) : telo(telo), sled(sled) {}
	};

	Elem* prvi_;
	Elem* posl_;

	void kopiraj(const Glista& g);
	void premesti(Glista& g);
	void brisi();
};