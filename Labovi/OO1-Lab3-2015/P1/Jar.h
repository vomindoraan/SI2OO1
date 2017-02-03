#ifndef _JAR_H_
#define _JAR_H_

#include "Item.h"

// Tegla
class Jar : public Item {
public:
	Jar(weight_type weight, len_type r, len_type h) :
		Item(weight), r_(r), h_(h)
	{}
	
	len_type getVolume() const override
	{
		static constexpr double PI = 3.141592653589793238463;
		return static_cast<len_type>(PI * r_ * r_ * h_);
	}

	Item* clone() const override
	{
		return new Jar(*this);
	}

protected:
	char getItemID() const override
	{
		return ID;
	}

	void writeToStream(std::ostream& os) const override
	{
		Item::writeToStream(os);
		os << ',' << r_ << ',' << h_;
	}

private:
	len_type r_, h_;
	static const char ID = 'T';

	friend class ItemFactory;

	static Jar* create()
	{
		std::cout << "Uneti tezinu, poluprecnik i visinu: ";
		weight_type weight;
		len_type r, h;
		std::cin >> weight >> r >> h;
		return new Jar(weight, r, h);
	}
};

#endif
