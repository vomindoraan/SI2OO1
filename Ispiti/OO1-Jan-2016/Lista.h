#pragma once

#include <iostream>

template <typename T>
class Lista {
public:
	Lista() : prvi_(nullptr), posl_(nullptr) {}
	Lista(const Lista&) = delete;
	~Lista();
	Lista& operator=(const Lista&) = delete;

	Lista& dodaj(const T& pod)
	{
		posl_ = (prvi_ ? posl_->sled : prvi_) = new Elem(pod);
		return *this;
	}

	Lista& operator+=(const T& pod) { dodaj(pod); }

	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const Lista<T>& ls);
	
protected:
	struct Elem {
		T pod;
		Elem* sled;
		Elem(const T& pod, Elem *sled = nullptr) : pod(pod), sled(sled) {}
	};

	Elem *prvi_;
	Elem *posl_;
};

template <typename T>
Lista<T>::~Lista()
{
	while (prvi_) {
		auto* stari = prvi_;
		prvi_ = prvi_->sled;
		delete stari;
	}
	prvi_ = posl_ = nullptr;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Lista<T>& ls)
{
	for (auto* p = ls.prvi_; p != nullptr; p = p->sled) {
		os << p->pod << std::endl;
	}
	return os << std::endl;
}
