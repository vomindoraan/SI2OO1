#ifndef _telo_h_
#define _telo_h_

#include <iostream>
using namespace std;

class Telo {
private:
	double sigma;
	char vrsta;
public:
	Telo(double ss, char vv) { sigma = ss; vrsta = vv; }

	virtual double zapremina() { return 0; }
	double tezina() { return zapremina()*sigma; }

	char dohvatiVrsta() { return vrsta; }
	double dohvatiSigma() { return sigma; }
	
	virtual void pisi(ostream &it) { it << vrsta << ":" << sigma; }
};

#endif;