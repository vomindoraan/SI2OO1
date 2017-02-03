#include "Timestamp.h"

#include <cstdlib> // std::div

// Sve metode koje su def. u samoj klasi, u header fajlu, su automatski inline
// Neke složenije metode, koje npr. imaju petlje ili pozive f-ja ne treba pisati
// u klasi, već samo navesti njihov potpis, a implementirati ih u .cpp fajlu

// Neophodno je proširiti plus sa Timestamp:: da bi se odnosilo na metod te klase
Timestamp Timestamp::plus(const Timestamp& other) const
{
	Timestamp res;

	auto d = std::div(s_ + other.s_, 60); // d = količnik i ostatak (kao struct)
	res.s_ = d.rem;                       // rem (ostatak) je preostali br. sek.

	d = std::div(m_ + other.m_ + d.quot, 60); // quot (količnik) ulazi u minute
	res.m_ = d.rem;

	res.h_ = h_ + other.h_ + d.quot;      // Isto za minute i sate
	return res;
}

// Ovde treba proširiti i CmpResult sa Timestamp:: jer je taj tip član klase
// U supr. će prevodilac tražiti CmpResult u globalnom dosegu imena i neće naći
Timestamp::CmpResult Timestamp::compare(const Timestamp& other) const
{
	auto ts = inSeconds(), os = other.inSeconds(); // Pretvara oba u sekunde
	return (ts < os)  ? BEFORE :
		   (ts == os) ? EQUAL :
		                AFTER;
}
