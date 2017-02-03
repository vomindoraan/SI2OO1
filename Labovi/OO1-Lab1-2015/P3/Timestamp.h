#ifndef _TIMESTAMP_H_
#define _TIMESTAMP_H_

#include <iostream>

// Vreme
class Timestamp {
public:
	// Povratni tip f-je poređenja. Kreće od -1 da bi bilo kao strcmp(): -1 0 1
	enum CmpResult { BEFORE = -1, EQUAL, AFTER };
	
	// Namerno bez explicit da bi moglo npr. Racer r1({1, 28, 14})
	// Nije 100% ispravno, ali za sad ne može bolje; explicit za sigurne poene
	Timestamp(unsigned h = 0, unsigned m = 0, unsigned s = 0) :
		h_(h), m_(m), s_(s)
	{}

	// Svi getter-i su const jer ne menjaju stanje objekta
	unsigned h() const { return h_; }
	unsigned m() const { return m_; }
	unsigned s() const { return s_; }

	// Sabira ovo Vreme sa prosleđenim i vraća rezultujuće Vreme *po vrednosti*
	Timestamp plus(const Timestamp& other) const;

	// Poredi 2 Vremena - arg je const jer ga metoda neće menjati (optimizacija)
	CmpResult compare(const Timestamp& other) const;

	void read()        { std::cin >> h_ >> m_ >> s_;  }
	void write() const { std::cout << h_ << ':' << m_ << ':' << s_; }

private:
	unsigned h_, m_, s_; // Pisanje _ posle imena priv. atributa je dobra praksa

	// Pomoćna f-ja koja pretvara Vreme u sekunde (olakšava poređenje)
	unsigned inSeconds() const { return h_*3600 + m_*60 + s_; }
};

#endif // !_TIMESTAMP_H_
