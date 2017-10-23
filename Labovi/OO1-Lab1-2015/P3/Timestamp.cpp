#include "Timestamp.h"

// Sve metode koje su def. u samoj klasi, u header fajlu, su automatski inline
// Neke složenije metode, koje npr. imaju petlje ili pozive f-ja ne treba pisati
// u klasi, već samo navesti njihov potpis, a implementirati ih u .cpp fajlu

// Neophodno je proširiti plus sa Timestamp:: da bi se odnosilo na metod te klase
Timestamp Timestamp::plus(const Timestamp& other) const
{
	auto s = s_ + other.s_;
	auto m = m_ + other.m_ + s / 60;
	auto h = h_ + other.h_ + m / 60;
	return Timestamp(h, m % 60, s % 60);
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
