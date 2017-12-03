#pragma once
#include <iostream>
#include <cstdlib>
#include "20162kvadar.h"
using namespace std;

class lista {
protected:
	struct elem {
		kvadar*pok;
		elem*next;
		elem(kvadar * p, elem * n = nullptr) {
			pok = p;
			next = n;
		}
	};
	elem*prvi;
	elem*posl;
	void brisi() {
		elem*tek = prvi;
		while (tek) {
			elem*stari = tek;
			tek = tek->next;
			delete stari;
		}
		prvi = posl = nullptr;
	}
	void premesti(lista &l1) {
		prvi = l1.prvi;
		posl = l1.posl;
		l1.prvi = nullptr;
		l1.posl = nullptr;
	}
	void kopiraj(lista &l) {
		elem*tek = l.prvi;
		elem*novi = nullptr;
		while (tek) {
			novi = new elem(tek->pok);
			if (prvi == nullptr) {
				prvi = posl = novi;
			}
			posl->next = novi;
			posl = posl->next;
			tek = tek->next;
		}
		
	}
	void pisi(ostream&it) {
		elem * tek = prvi;
		it << "[";
		while (tek) {
			if (tek != prvi) {
				cout << " | ";
			}
			it << *tek->pok;
			tek = tek->next;
		}
		it << "]" << endl;
	}
public:
	lista(elem *f = nullptr, elem * l = nullptr) {
		prvi = f;
		posl = l;
	}
	lista& operator=(lista& l1) {
		if (this != &l1) {
			brisi();
			kopiraj(l1);
		}
		return*this;
	}
	friend ostream&operator<<(ostream&it, const kvadar&k) {
		k.pisi(it);
		return it;
	}
};