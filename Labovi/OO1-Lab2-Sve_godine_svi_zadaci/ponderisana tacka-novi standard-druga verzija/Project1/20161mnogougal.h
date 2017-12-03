#pragma once
#include "20161tacka.h"
#include "20161napuderisanaTacka.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;
class mnogougal {
private:
	void brisi();
	void kopiraj(const mnogougal& m);
	tacka ** niz;
	int kap;
	int pop;
	void premesti(mnogougal& m);
public:
	~mnogougal() { brisi(); }
	mnogougal(const mnogougal &m) { kopiraj(m); }
	mnogougal(mnogougal &&m) { premesti(m); }
	explicit mnogougal(int kkap = 3) : kap(kkap) {
		niz = new tacka*[kkap];
		pop = 0;
		for (int i = 0; i < kkap; i++) { niz[i] = nullptr; }
	}
	void operator+= (tacka& t1)
	{
		if (pop == kap) exit(1);
		niz[pop++] = t1.klon();
	}
	mnogougal& operator= (const mnogougal& m1) {
		if (this != &m1) {
			brisi();
			kopiraj(m1);
		}
		return *this;
	}
	mnogougal& operator= (mnogougal&& m1) {
		if (this != &m1) {
			brisi();
			premesti(m1);
		}
		return *this;
	}
	friend ostream& operator<<(ostream&it, const mnogougal& m) {
		it << "[ ";
		for (int i = 0; i < m.pop; i++) {
			if (i != 0) it << "|";
			cout << *m.niz[i];
		}
		it << " ]" << endl;
		return it;
	}
};