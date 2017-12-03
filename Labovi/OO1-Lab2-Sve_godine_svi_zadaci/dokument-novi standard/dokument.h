#ifndef _DOKUMENT_H_
#define _DOKUMENT_H_

#include <string>

#include <iostream>
using namespace std;

class Dokument {
private:
	void brisi() {
		if (pniz == nullptr) return;
		delete [] pniz; 
	}

	void kopiraj(const Dokument &d);

	void premesti(Dokument &d) {
		kap = d.kap;
		pop = d.pop;
		pniz = d.pniz;
		d.pniz = nullptr;
	}
protected:
	int id;
	static int ukId;
	string *pniz;
	int kap, pop;

	virtual void pisi(ostream &it) const;
public:
	explicit Dokument(int kkap=5) {
		kap = kkap;
		pop = 0;
		id = ukId++;
		pniz = new string[kap];
	}

	virtual ~Dokument() { brisi(); }

	//kod svih mogucih nacina kopiranja objekta, obezbedjujemo jedinstvenost id broja
	Dokument(const Dokument &d) {
		id = ukId++; //uzme novi id
		kopiraj(d);
	}

	Dokument(Dokument &&d) {
		id = ukId++;
		premesti(d);
	}

	Dokument &operator=(const Dokument &d) {
		if (this != &d) {
			brisi();
			kopiraj(d);
			//ne kopira se id, svako vec ima svoj
		}
		return *this;
	}

	Dokument &operator=(Dokument &&d) {
		if (this != &d) {
			brisi();
			premesti(d);
			//ne kopira se id, svako vec ima svoj
		}
		return *this;
	}

	virtual Dokument *kopija() const { return new Dokument(*this); }

	Dokument &operator+=(const string &s) {
		if (kap == pop) exit(2);
		pniz[pop++] = s;
		return *this;
	}

	int getPop() const { return pop; }

	//virtuelna, jer se drugacije racuna u izvedenoj klasi
	virtual int duzina() const;

	friend ostream &operator<<(ostream &it, const Dokument &d) {
		d.pisi(it);
		return it;
	}
};

#endif