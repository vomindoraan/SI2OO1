#pragma once

#include "MaterijalnaTacka.h"

#include <iostream>
#include <cstdlib>

class NizTacaka {
public:
	static const unsigned D_KAP = 5;

	NizTacaka(unsigned kap = D_KAP) :
		kap_(kap), br_(0) // opciono
	{
		if (!kap) {
			std::cerr << "kapacitet ne moze biti 0" << std::endl;
			std::exit(1);
		}
		niz_ = new MaterijalnaTacka[kap];
	}

	NizTacaka(const NizTacaka& n);
	NizTacaka(NizTacaka&& n);
	~NizTacaka();

	unsigned brTacaka() const { return br_; }
	MaterijalnaTacka& najTacka() const;

	NizTacaka& dodaj(const MaterijalnaTacka& mt)
	{
		if (br_ == kap_) {
			prosiri(D_KAP);
		}
		niz_[br_++] = mt;
		return *this;
	}

	void ispis() const;

private:
	unsigned kap_, br_;
	MaterijalnaTacka* niz_;

	void prosiri(unsigned dKap);
};
