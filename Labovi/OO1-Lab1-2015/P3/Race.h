#ifndef _RACE_H_
#define _RACE_H_

#include "Racer.h"

#include <iostream>

// Trka
class Race {
public:
	// explicit jer nema naročitog smisla da se jedan broj pretvori u celu Trku
	explicit Race(unsigned capacity) :
		capacity_(capacity), size_(0),
		racers_(capacity ? new Racer*[capacity] : nullptr)
	{}
	
	// Ova klasa upravlja nekim resursom (dinamički niz), pa pored svog ktor-a
	// mora imati i:   • kopirajući ktor   • premeštajući ktor   • destruktor
	// (kasnije i:     • kopirajući operator=     • premeštajući operator=   )

	Race(const Race& other); // Kopirajući ktor   (prima const lvalue ref)
	Race(Race&& other);      // Premeštajući ktor (prima rvalue/xvalue ref)
	~Race();                 // Destruktor

	// Ova metoda će napraviti *kopiju* Trkača i onda taj pok. zapamtiti u niz
	bool add(const Racer& racer);

	void write() const; // Ne definiše se u klasi zato što u sebi sadrži petlju

private:
	unsigned capacity_, size_;
	Racer**  racers_; // Dinamički alociran niz pokazivača, stoga **
};

#endif // !_RACE_H_
