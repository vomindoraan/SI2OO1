#pragma once

#include "Roba.h"
#include "Zbirka.h"

#include <iostream>

class Paket : public Roba {
public:
	Paket& operator+=(Roba& r)
	{
		zbirka_ += r;
		return *this;
	}
	
	double vrednost() const override;

	Roba* kopiraj() const override;

protected:
	void ispis(std::ostream& os) const override;

private:
	Zbirka<Roba> zbirka_;
};