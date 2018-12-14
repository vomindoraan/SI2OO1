#ifndef _OTPORNIK_H_
#define _OTPORNIK_H_

#include <iostream>
using namespace std;

class Otpornik {
protected: //stavili smo u protected da bi videle izvedene klase
	virtual void pisi(ostream &it) const = 0;
public:
	Otpornik() {} //nije moralo da se pise

	virtual ~Otpornik() {} //uvek u osnovnoj klasi ostavi virtuelan prazan destruktor

	virtual double otpornost() const = 0; //metoda je apstraktna, mora da se definise u izvedenoj klasi

	virtual Otpornik *kopija() const = 0;

	//funkcija ne moze da bude polimorfna (ili apstraktna), to moze samo metoda
	//da bismo ostvarili polimorfizam, f-ja zove polimorfnu metodu za pisanje
	friend ostream &operator<<(ostream &it, const Otpornik &o) { 
		o.pisi(it);
		return it;
	}
};

#endif