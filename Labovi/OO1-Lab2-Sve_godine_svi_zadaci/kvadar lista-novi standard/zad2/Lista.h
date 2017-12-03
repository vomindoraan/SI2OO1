#ifndef _Lista_h_
#define _Lista_h_

#include "kvadar.h"

class Lista{
private: 
	void brisi(){
		 while (prvi){
			Elem *stari=prvi;
			prvi=prvi->sled;
			delete stari;
		}
	}

	void kopiraj(const Lista &l1){
		prvi=posl=0;
		for (Elem *tek=l1.prvi;tek;tek=tek->sled){
			*this+=tek->kv;
		}
	}

	void premesti(Lista &l1) {
		prvi = l1.prvi;
		posl = l1.posl;
		l1.prvi = nullptr;
		l1.posl = nullptr;
	}
protected: 
	struct Elem{
	   Kvadar kv;
	   Elem* sled;
	   explicit Elem(const Kvadar &k1, Elem *sl = nullptr) : kv(k1) { sled = sl; }
	};
		    
	Elem *prvi,*posl;

	virtual void pisi(ostream &it) const {
		it << "[";
		for (Elem *tek = prvi; tek; tek = tek->sled){
			if (tek == prvi) it << tek->kv;
			else it << "|" << tek->kv;
			it << "]";
		}
	}
public:  
	Lista() { prvi=posl=nullptr; }
	 
	virtual ~Lista() { brisi(); }
		 
	Lista(const Lista &l1) { kopiraj(l1); }

	Lista(Lista &&l1) { premesti(l1); }

	Lista &operator=(const Lista &l1){
		if (this!=&l1){
			brisi();
			kopiraj(l1);
		}
		return *this;
	}

	Lista &operator=(Lista &&l1){
		if (this != &l1){
			brisi();
			premesti(l1);
		}
		return *this;
	}

	virtual Lista *kopija() const { return new Lista(*this); }

	virtual Lista& operator+=(const Kvadar& kv){
		Elem *novi=new Elem(kv);
		if (prvi==nullptr) 
			prvi=posl=novi;
		else {
			posl->sled=novi;
			posl=novi;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& it, const Lista& l){
		l.pisi(it);
		return it;
	}
};
		
#endif