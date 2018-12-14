#ifndef _SKUP_H_
#define _SKUP_H_

#include "zbirka.h"

class Skup : public Zbirka {
protected:

public:
	Skup(int kkap=10, int kor=4) : Zbirka(kkap, kor) {}

	Skup &operator+=(int broj);
};

#endif