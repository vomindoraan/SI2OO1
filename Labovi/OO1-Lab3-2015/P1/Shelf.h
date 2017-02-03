#ifndef _SHELF_H_
#define _SHELF_H_

#include "Item.h"

#include <cstddef>
#include <iostream>
#include <stdexcept>

// Polica
template <typename T>
class Shelf {
public:
	explicit Shelf(std::size_t size = 10, Item::weight_type maxWeight = 100);

	Shelf(const Shelf& other);

	Shelf(Shelf&& other);

	~Shelf();

	Shelf& operator=(Shelf other) // Kopirajuca i premestajuca dodela (copy-swap idiom)
	{
		swap(other);
		return *this;
	}

	void put(T* item);

	T* take(std::size_t index);

	std::size_t getRemainingSpace();

	Item::weight_type getRemainingWeight()
	{
		return maxWeight_ - weight_;
	}

	Shelf& operator<<(T* item)
	{
		put(item);
		return *this;
	}

	T* operator>>(std::size_t index)
	{
		return take(index);
	}

	friend std::ostream& operator<<(std::ostream& os, const Shelf& shelf)
	{
		os << '[';
		for (std::size_t i = 0, b = 0; i < shelf.size_; ++i) {
			T* item = shelf.contents_[i];
			if (item != nullptr) {
				if (b++) {
					os << ',';
				}
				os << *item;
			}
		}
		return os << ']';
	}

	class FullException : public std::exception {
		const char* what() const override
		{
			return "Polica je puna!";
		}
	};

	class OverloadException : public std::exception {
		const char* what() const override
		{
			return "Polica je preopterecena!";
		}
	};

	class NoSuchItemException : public std::exception {
		const char* what() const override
		{
			return "Taj predmet ne postoji!";
		}
	};

private:
	std::size_t size_, free_;
	Item::weight_type maxWeight_, weight_;
	T** contents_;

	void swap(Shelf& other);
};

template <typename T>
Shelf<T>::Shelf(std::size_t size, Item::weight_type maxWeight) :
	size_(size), free_(0), maxWeight_(maxWeight), weight_(0),
	contents_(size ? new T*[size] : nullptr)
{
	if (!size) {
		throw std::invalid_argument("Velicina ne moze biti 0!");
	}
	for (std::size_t i = 0; i < size; ++i) {
		contents_[i] = nullptr;
	}
}

template <typename T>
Shelf<T>::Shelf(const Shelf& other) :
	size_(other.size_), free_(other.free_), maxWeight_(other.maxWeight_), weight_(other.weight_),
	contents_(new T*[other.size_])
{
	for (std::size_t i = 0; i < size_; ++i) {
		contents_[i] = (other.contents_[i] != nullptr) ? other.contents_[i]->clone() : nullptr;
	}
}

template<typename T>
inline Shelf<T>::Shelf(Shelf && other) :
	size_(other.size_), free_(other.free_), maxWeight_(other.maxWeight_), weight_(other.weight_),
	contents_(other.contents_)
{
	other.contents_ = nullptr;
}

template <typename T>
Shelf<T>::~Shelf()
{
	for (std::size_t i = 0; i < size_; ++i) {
		delete contents_[i];
	}
	delete[] contents_;
}


template <typename T>
void Shelf<T>::put(T* item)
{
	if (free_ == size_) {
		throw FullException();
	} else if (weight_ + item->getWeight() >= maxWeight_) {
		throw OverloadException();
	}

	contents_[free_] = item;
	weight_ += item->getWeight();
	for (; free_ < size_ && contents_[free_] != nullptr; ++free_);
}

template <typename T>
T* Shelf<T>::take(std::size_t index)
{
	if (index < 0 || index >= size_) {
		throw std::out_of_range("To mesto ne postoji!");
	} else if (contents_[index] == nullptr) {
		throw NoSuchItemException();
	}

	T* item = contents_[index];
	contents_[index] = nullptr;
	if (index < free_) {
		free_ = index;
	}
	return item;
}

template <typename T>
std::size_t Shelf<T>::getRemainingSpace()
{
	auto space = size_;
	for (std::size_t i = 0; i < size_; ++i) {
		space -= (contents[i] == nullptr);
	}
	return space;
}

template <typename T>
void Shelf<T>::swap(Shelf& other)
{
	std::swap(size_, other.size_);
	std::swap(free_, other.size_);
	std::swap(maxWeight_, other.maxWeight_);
	std::swap(weight_, other.weight_);
	std::swap(contents_, other.contents_);
}

#endif
