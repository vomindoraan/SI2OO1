#pragma once

#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class Zbirka {
public:
	Zbirka(unsigned kap = 10, unsigned dkap = 3)
		: kap_(kap)
		, dkap_(dkap)
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

	Zbirka& operator+=(T& elem);

	T* operator[](unsigned i)
	{
		if (i >= duz_) {
			throw std::out_of_range("Nedozvoljen redni broj");
		}
		return niz_[i];
	}

	const T* operator[](unsigned i) const
	{
		return const_cast<Zbirka&>(*this)[i];
	}

	T&& izvadi(unsigned i); // && da bi radilo sa apstraktnom klasom

	unsigned duzina() const { return duz_; }

	friend void swap(Zbirka& z1, Zbirka& z2)
	{
		using std::swap;
		swap(z1.kap_, z2.kap_);
		swap(z1.duz_, z2.duz_);
		swap(z1.niz_, z2.niz_);
	}

private:
	unsigned kap_, dkap_, duz_;
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
Zbirka<T>& Zbirka<T>::operator+=(T& elem)
{
	if (duz_ == kap_) {
		T** tmp = new T*[kap_ += dkap_];
		for (unsigned i = 0; i < duz_; ++i) {
			tmp[i] = niz_[i];
		}
		delete[] niz_;
		niz_ = tmp;
	}
	niz_[duz_++] = elem.kopiraj();
	return *this;
}

template <typename T>
T&& Zbirka<T>::izvadi(unsigned i)
{
	T&& res = std::move((*this)[i]);
	delete niz_[i];
	for (auto j = i; j < duz_--; j++) {
		niz[j] = niz[j+1];
	}
	return res;
}
