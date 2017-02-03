#include "Telo.h"
#include "Lopta.h"
#include "Valjak.h"
#include "Glista.h"

#include <iostream>

using namespace std;

int main()
{
	Glista g;
	Lopta lp1(2.5, 10.0), *lp2 = new Lopta(5.0, 8.4);
	Valjak v(7.0, 15.0, 12.5);
	g += lp1;
	g += v;
	g += *lp2;
	g += Valjak(2.33, 1.5, 0.45);
	cout << g << endl;
	return 0;
}
