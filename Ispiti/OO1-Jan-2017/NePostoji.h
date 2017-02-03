#pragma once

#include <exception>
using namespace std;

class NePostoji : public exception {
public:
	NePostoji() : exception("Ne postoji element liste") {}
};
