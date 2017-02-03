#ifndef _ITEM_FACTORY_H_
#define _ITEM_FACTORY_H_

#include "Box.h"
#include "Jar.h"

// Fabrika za predmete
class ItemFactory {
public:
	ItemFactory(const ItemFactory& other) = delete;

	void operator=(const ItemFactory& other) = delete;

	Item* createItem(char id) const
	{
		switch (id) { // Ne sme std::map, pa mora ovako nekako
		case Box::ID:
			return Box::create();
		case Jar::ID:
			return Jar::create();
		default:
			return nullptr;
		}
	}

	// Singleton
	static ItemFactory& getInstance()
	{
		static ItemFactory factory;
		return factory;
	}

private:
	ItemFactory() {}
};

#endif
