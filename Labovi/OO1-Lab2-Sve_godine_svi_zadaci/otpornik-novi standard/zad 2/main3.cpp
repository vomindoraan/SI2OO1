#include "otpornik.h"
#include "prost.h"
#include "slozen.h"
#include "redna.h"

int main() {
	Redna red1(3);

	red1 += Prost(5.5);
	red1 += Prost(4.4);
	red1 += Prost(9);

	Redna veza(4);

	veza += red1;
	veza += Prost(4.3);
	veza += Prost(1.1);
	veza += red1;

	cout << veza << endl << endl;

	return 0;
}