#include "telo.h"
#include "valjak.h"
#include "lopta.h"
#include "glista.h"
#include <iostream>
using namespace std;

void main() {
	Glista g;
	Telo *telo = new Lopta(12, 2);
	g += telo;
	telo = new Valjak(1,2,3);
	g += telo;
	cout << g;
}