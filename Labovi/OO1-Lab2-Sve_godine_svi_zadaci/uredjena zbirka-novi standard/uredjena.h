#ifndef _UREDJENA_H_
#define _UREDJENA_H_

#include "zbirka.h"

class Uredjena : public Zbirka {
public:
	Uredjena(int kkap=10, int kor=4) : Zbirka(kkap, kor) {}

	Uredjena &operator+=(int broj);
};

#endif