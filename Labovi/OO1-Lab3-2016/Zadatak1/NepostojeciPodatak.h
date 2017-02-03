#pragma once

#include <exception>

class NepostojeciPodatak : public std::exception {
public:
	NepostojeciPodatak()
		: std::exception("Podatak ne postoji")
	{}
};