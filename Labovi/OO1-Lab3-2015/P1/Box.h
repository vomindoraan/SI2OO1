#ifndef _BOX_H_
#define _BOX_H_

#include "Item.h"

// Kutija
class Box : public Item {
public:
	Box(weight_type weight, len_type a, len_type b, len_type c) :
		Item(weight), a_(a), b_(b), c_(c)
	{}

	len_type getVolume() const override
	{
		return a_ * b_ * c_;
	}

	Item* clone() const override
	{
		return new Box(*this);
	}

protected:
	char getItemID() const override
	{
		return ID;
	}

	void writeToStream(std::ostream& os) const override
	{
		Item::writeToStream(os);
		os << ',' << a_ << ',' << b_ << ',' << c_;
	}

private:
	len_type a_, b_, c_;
	static const char ID = 'K';

	friend class ItemFactory;

	static Box* create()
	{
		std::cout << "Uneti tezinu i duzine ivica a, b, c: ";
		weight_type weight;
		len_type a, b, c;
		std::cin >> weight >> a >> b >> c;
		return new Box(weight, a, b, c);
	}
};

#endif
