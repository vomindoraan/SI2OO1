#include "Race.h"
#include "Time.h" // Time::AFTER

Race::Race(const Race& other) :
	capacity_(other.capacity_), size_(other.size_),
	racers_(other.capacity_ ? new Racer*[other.capacity_] : nullptr)
{
	for (unsigned i = 0; i < size_; ++i) {
		 racers_[i] = other.racers_[i];
	}
}

Race::Race(Race&& other) :
	capacity_(other.capacity_), size_(other.size_),
	racers_(other.racers_)
{
	other.racers_ = nullptr; // Obavezno drugi na null! U supr. se podaci brišu
}

Race::~Race()
{
	for (unsigned i = 0; i < size_; ++i) {
		delete racers_[i]; // Brišu se Trkači (njihove kopije)
	}
	delete[] racers_;  // Briše se sam niz
	racers_ = nullptr; // pok = nullptr posle delete[] je dobra praksa, kinda :P
}

bool Race::add(const Racer& racer)
{
	if (size_ == capacity_) {
		return false;
	}

	unsigned i;
	for (i = size_; i > 0; --i) { // Nalazi indeks i na kog treba ubaciti Trkača
		auto t1 = racers_[i-1]->time(), t2 = racer.time();
		if (t1.compare(t2) != Time::AFTER) {
			break;
		}
		racers_[i] = racers_[i-1]; // Pomera ostale Trkače naviše
	}

	racers_[i] = new Racer(racer);
	// Dinamički se stvara novi Trkač obj. pozivom podraz. *kopirajućeg ktor-a*
	// Racer(const Racer&). Kopija se pravi zato što, ako prosleđeni obj. racer
	// prestane da živi (uništi se) van kontrole Trke koja ga sadrži, u nizu
	// će ostati pok. koji sad pokazuje na slobodnu mem. i može izazvati pucanje

	// Kad se napravi kopija, problema nema jer sad Trka upravlja životnim vekom
	// svih Trkača koje sadrži, makar originali bili uništeni

	++size_;
	return true;
}

void Race::write() const
{
	for (unsigned i = 0; i < size_; ++i) {
		racers_[i]->write();
		std::cout << std::endl;
	}
}
