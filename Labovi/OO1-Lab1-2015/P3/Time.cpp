#include "Time.h"

// Sve metode koje su def. u samoj klasi, u zaglavlju, su automatski inline
// Neke složenije metode, koje npr. imaju petlje ili pozive f-ja ne treba pisati
// u klasi, već samo navesti njihov potpis, a implementirati ih u .cpp fajlu

// Neophodno je proširiti plus sa Time:: da bi se odnosilo na metod te klase
Time Time::plus(const Time& other) const
{
	auto s = s_ + other.s_;
	auto m = m_ + other.m_ + s / 60;
	auto h = h_ + other.h_ + m / 60;
	// Može se koristiti inic. lista, a prevodilac zna da treba da stvori Time
	return { h, m % 60, s % 60 };
}

// Ovde treba proširiti i CmpResult sa Time:: jer je taj tip član klase
// U supr. će prevodilac tražiti CmpResult u globalnom dosegu imena i neće naći
Time::CmpResult Time::compare(const Time& other) const
{
	auto ts = inSeconds(), os = other.inSeconds(); // Pretvara oba u sekunde
	return (ts < os)  ? BEFORE :
	       (ts == os) ? EQUAL :
	                    AFTER;
}
