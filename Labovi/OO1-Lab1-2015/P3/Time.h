#ifndef _TIME_H_
#define _TIME_H_

#include <iostream>

// Vreme
class Time {
public:
	// Povratni tip f-je poređenja; kreće od -1 da bi bilo kao strcmp(): -1 0 1
	enum CmpResult { BEFORE = -1, EQUAL, AFTER };
	
	// Namerno bez explicit da bi moglo npr. Racer r1({1, 28, 14})
	// Nije 100% ispravno, ali za sad ne može bolje; explicit za sigurne poene
	Time(unsigned h = 0, unsigned m = 0, unsigned s = 0) :
		h_(h), m_(m), s_(s)
	{}

	// Svi getter-i su const jer ne menjaju stanje objekta
	// C++14 omogućava da povr. tip f-je bude auto tamo gde se može zaključiti
	auto h() const { return h_; }
	auto m() const { return m_; }
	auto s() const { return s_; }

	// Sabira ovo Vreme sa prosleđenim i vraća rezultujuće Vreme *po vrednosti*
	Time plus(const Time& other) const;

	// Poredi 2 Vremena - arg je const jer ga metoda neće menjati (optimizacija)
	CmpResult compare(const Time& other) const;

	void read()        { std::cin >> h_ >> m_ >> s_;  }
	void write() const { std::cout << h_ << ':' << m_ << ':' << s_; }

private:
	unsigned h_, m_, s_; // Pisanje _ posle imena priv. atributa je dobra praksa

	// Pomoćna f-ja koja pretvara Vreme u sekunde (olakšava poređenje)
	auto inSeconds() const { return h_*3600 + m_*60 + s_; }
};

#endif // !_TIME_H_
