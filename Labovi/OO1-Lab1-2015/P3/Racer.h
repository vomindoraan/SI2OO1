#ifndef _RACER_H_
#define _RACER_H_

#include "Time.h"

#include <iostream>
#include <string>

// Trkač
class Racer {
public:
	const std::string name; // Javno jer se nikad ne menja

	// Namerno bez explicit da bi moglo npr. race.add("Pera Perić")
	Racer(const std::string& name) :
		name(name) // Kod std::string-ova ne treba nikakvo posebno kopiranje
	{}

	// time_ je privatno pa mu trebaju getter i setter
	const Time& time() const     { return time_; }
	void time(const Time& value) { time_ = value; } // Setter nije const

	void write() const {
		std::cout << '[' << name << " - ";
		time_.write();
		std::cout << ']';
	}

private:
	Time time_;
	// Iako time_ nije postavljeno u ktor-u, automatski je (0,0,0) zato što se
	// svi atributi na početku inic. svojim podraz. ktor-om (npr. Time())
};

#endif // !_RACER_H_
