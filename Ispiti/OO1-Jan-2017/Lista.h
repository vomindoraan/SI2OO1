#pragma once

#include "NePostoji.h"
#include <iostream>

template <typename T>
class Lista {
public:
	Lista() : prvi_(nullptr), posl_(nullptr), tek_(nullptr), vel_(0) {}
	Lista(const Lista&) = delete;
	~Lista();

	Lista& operator=(const Lista&) = delete;

	Lista& dodaj(const T& pod, int vr)
	{
		posl_ = (!prvi_ ? prvi_ : posl_->sled) = new Elem(pod, vr);
		++vel_;
		return *this;
	}

	int velicina() const { return vel_; }

	void naPocetak() const { tek_ = prvi_; }
	void naSledeci() const { tek_ = tek_->sled; }
	bool postoji() const { tek_ != nullptr; }

	T& podatak()
	{
		if (!postoji()) { throw NePostoji(); }
		return tek_->pod;
	}

	const T& podatak() const { return const_cast<Lista&>(*this).podatak(); }

	int& vrednost()
	{
		if (!postoji()) { throw NePostoji(); }
		return tek_->vr;
	}

	const int& vrednost() const { return const_cast<Lista&>(*this).vrednost(); }

private:
	struct Elem {
		T& pod;
		int vr;
		Elem* sled;

		Elem(const T& pod, int vr, Elem* sled = nullptr)
			: pod(pod), vr(vr), sled(sled)
		{}
	};

	Elem* prvi_;
	Elem* posl_;
	mutable Elem* tek_;
	int vel_;
};

template <typename T>
Lista<T>::~Lista()
{
	while (prvi_ != nullptr) {
		auto stari = prvi_;
		prvi_ = prvi_->sled;
		// Drugi nacin: auto stari = exchange(prvi_, prvi_->sled);
		delete stari;
	}
	posl_ = tek_ = nullptr;
}
