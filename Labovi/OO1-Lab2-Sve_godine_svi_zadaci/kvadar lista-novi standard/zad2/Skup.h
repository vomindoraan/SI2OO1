#ifndef _skup_h_
#define _skup_h_

#include "Lista.h"

class Skup: public Lista{
public: 
	 Skup(): Lista() {}

	 Skup *kopija() const override { return new Skup(*this); }

	 Skup& operator+=(const Kvadar& kv) override {	 
		for (Elem* tek = prvi; tek; tek=tek->sled){
			if (tek->kv == kv) return *this;
		}
		Lista::operator+=(kv);		 
		return *this;
	 }

};

#endif

