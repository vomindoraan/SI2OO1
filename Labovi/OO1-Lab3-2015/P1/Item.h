#ifndef _ITEM_H_
#define _ITEM_H_

#include <iostream>

// Predmet
class Item {
public:
	using weight_type = double;
	using len_type = unsigned;

	explicit Item(weight_type weight = 1) :
		weight_(weight)
	{}

	virtual ~Item() {}

	weight_type getWeight() const
	{
		return weight_;
	}

	virtual len_type getVolume() const = 0;

	virtual Item* clone() const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Item& item)
	{
		os << item.getItemID() << '(';
		item.writeToStream(os);
		return os << ')';
	}

protected:
	virtual char getItemID() const = 0;

	virtual void writeToStream(std::ostream& os) const
	{
		os << weight_;
	}

private:
	weight_type weight_;
};

#endif
