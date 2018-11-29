#include "Polje.h"
#include "Figure.h"
#include "SahovskaTabla.h"

#include <iostream>

int main()
{
	SahovskaTabla st;
	Polje p('D', 3);
	st += Top(Boja::CRNA, Polje('C', 3));
	st += Lovac(Boja::BELA, p);

	std::cout << st << "\n";
	std::cout << st(Polje('C', 3), Polje('F', 8)) << "\n";
	std::cout << st << "\n";
	std::cout << st(Polje('C', 3), Polje('C', 4)) << "\n";
	std::cout << st << "\n";
	std::cout << st(p, Polje('C', 4)) << "\n";
	std::cout << st << "\n";
}
