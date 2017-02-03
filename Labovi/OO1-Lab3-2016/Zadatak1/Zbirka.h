#pragma once

#include "ZbirkaPuna.h"
#include "NepostojeciPodatak.h"

#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class Zbirka {
public:
	Zbirka(unsigned kap = 10)
		: kap_(kap)
		, duz_(0)
	{
		if (kap == 0) {
			throw std::invalid_argument("Kapacitet ne moze biti 0");
		}
		niz_ = new T*[kap];
	}

	Zbirka(const Zbirka& z);

	Zbirka(Zbirka&& z);

	~Zbirka();

	Zbirka& operator=(Zbirka z)
	{
		swap(*this, z);
		return *this;
	}

	Zbirka& operator+=(T* elem)
	{
		if (duz_ == kap_) {
			throw ZbirkaPuna();
		}
		niz_[duz_++] = new T(*elem);
		return *this;
	}

	T* operator[](unsigned i)
	{
		if (i >= duz_) {
			throw NepostojeciPodatak();
		}
		return niz_[i];
	}

	const T* operator[](unsigned i) const
	{
		return const_cast<Zbirka&>(*this)[i];
	}

	unsigned duzina() const { return duz_; }

	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const Zbirka<T>& z);

	friend void swap(Zbirka& z1, Zbirka& z2)
	{
		using std::swap;
		swap(z1.kap_, z2.kap_);
		swap(z1.duz_, z2.duz_);
		swap(z1.niz_, z2.niz_);
	}
	
private:
	unsigned kap_, duz_;
	T** niz_;
};

template <typename T>
Zbirka<T>::Zbirka(const Zbirka& z)
	: kap_(z.kap_)
	, duz_(z.duz_)
	, niz_(new T*[z.kap_])
{
	for (unsigned i = 0; i < duz_; ++i) {
		niz_[i] = z.niz_[i];
	}
}

template <typename T>
inline Zbirka<T>::Zbirka(Zbirka&& z)
	: kap_(z.kap_)
	, duz_(z.duz_)
	, niz_(z.niz_)
{
	z.niz_ = nullptr;
}

template <typename T>
Zbirka<T>::~Zbirka()
{
	for (unsigned i = 0; i < duz_; ++i) {
		delete niz_[i];
	}
	delete[] niz_;
	niz_ = nullptr;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Zbirka<T>& z)
{
	os << '{';
	auto duz = z.duzina();
	for (unsigned i = 0; i < duz; ++i) {
		os << *z[i] << (i < duz-1 ? ',' : '}');
	}
	return os;
}
