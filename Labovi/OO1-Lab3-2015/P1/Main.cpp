#include "Box.h"
#include "Jar.h"
#include "Shelf.h"
#include "ItemFactory.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#define DELAY 2000

#ifdef _WIN32
#include <windows.h>
#define CLEAR() system("cls")
#define SLEEP() Sleep(DELAY)
#else
#include <unistd.h> // Pretpostavljamo POSIX
#define CLEAR() system("clear")
#define SLEEP() sleep(DELAY)
#endif

void readPutItem(Shelf<Item>& shelf)
{
	Item* item = nullptr;
	do {
		std::cout << "Uneti vrstu predmeta (npr. K ili T): ";
		char id;
		std::cin >> id;
		item = ItemFactory::getInstance().createItem(id);
	} while (item == nullptr);
	shelf << item;
}

void takeWriteItem(Shelf<Item>& shelf)
{
	std::cout << "Uneti indeks predmeta: ";
	std::size_t index;
	std::cin >> index;
	std::cout << (shelf >> index);
}

const char* msgs[] = {
	"Procitaj i stavi",
	"Uzmi i ispisi",
	"Ispisi sve",
	"Zavrsi"
};

bool menu(Shelf<Item>& shelf)
{
	CLEAR();
	unsigned i = 1;
	for (auto msg : msgs) {
		std::cout << i++ << ". " << msg << std::endl;
	}

	unsigned choice;
	std::cin >> choice;
	std::cout << std::endl;
	
	try {
		switch (choice) {
		case 1:
			readPutItem(shelf);
			return true;
		case 2:
			takeWriteItem(shelf);
			break;
		case 3:
			std::cout << shelf << std::endl;
			break;
		case 4:
			return false;
		default:
			std::cout << "Pogresan unos" << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	SLEEP();
	return true;
}

int main()
{
	Shelf<Item> shelf(5, 50);
	while (menu(shelf));

	Shelf<Item> shelf2(shelf);
	std::cout << "Kopija: " << shelf2 << std::endl;
	shelf2 = Shelf<Item>();
	std::cout << "Premestanje: " << shelf2 << std::endl;

	return 0;
}
