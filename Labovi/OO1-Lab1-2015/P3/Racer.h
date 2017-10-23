#ifndef _RACER_H_
#define _RACER_H_

#include "Time.h"

#include <iostream>
#include <string> // U C++ uvek std::string, nikad char* ako ne mora

// Trkač
class Racer {
public:
	const std::string name; // Javan jer se ne menja; ne treba getter/setter

	// Namerno bez explicit da bi moglo npr. race.add("Pera Perić")
	Racer(const std::string& name) :
		name(name) // Kod stringova ne treba posebno kopiranje, za razl od char*
	{}

	// time_ je privatan pa mu trebaju getter i setter
	// Getter vraća ref. preko koje se Vreme trkača može čitati ali ne i menjati
	// Setter nije const jer menja stanje (atribut) objekta
	const Time& time() const     { return time_; }
	void time(const Time& value) { time_ = value; }

	void write() const {
		std::cout << '[' << name << " - ";
		time_.write();
		std::cout << ']';
	}

private:
	Time time_;
	// Iako time_ nije postavljeno u ktor-u, automatski je (0,0,0) zato što se
	// svi atributi na početku prave svojim podraz. ktor-om (npr. Time())
};

#endif // !_RACER_H_
