#include "tacka.h"
#include "merenje.h"
#include "mernatacka.h"
#include "zbirkamt.h"

#include <iostream>
using namespace std;

int main() {
	ZbirkaMT zmt(3);

	MernaTacka mt(2);
	
	mt += Merenje(20, 5000);	
	mt += Merenje(30, 7000);

	zmt += mt;

	mt = MernaTacka(3);
	mt += Merenje(40, 6000);	
	mt += Merenje(50, 5000);	
	mt += Merenje(20, 7000);

	zmt += mt;

	cout << "Srednja: " << zmt(4500,6500) << endl;
	return 0;
}