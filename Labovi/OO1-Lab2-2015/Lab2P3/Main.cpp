#include "SimpleResistor.h"
#include "SerialLink.h"

#include <iostream>
#include <cstdlib>

int main()
{
	SimpleResistor r1(10), r2(250), r3(0.25), r4(15600);
	std::cout << "Prosti otpornici r1..4: " << std::endl;
	std::cout << r1 << ", " << r2 << ", " << r3 << ", " << r4 << std::endl;

	SerialLink serial1(5), serial2(2);
	serial1 += r1;
	serial1 += r2;
	serial1 += r3;
	serial1 += r4;
	std::cout << "\nRedna veza serial1 (kapacitet 5): " << std::endl;
	std::cout << serial1 << std::endl;;

	std::cout << "\nRedna veza serial2 (kapacitet 2):" << std::endl;
	std::cout << "Ubacivanje serial1 u serial2: " << (serial2 += serial1) << std::endl;
	std::cout << "Ubacivanje r3 u serial2: " << (serial2 += r3) << std::endl;
	std::cout << "Ubacivanje novog otp. u serial2: " << (serial2 += SimpleResistor(0.33)) << std::endl;

	auto serial3 = serial2;
	std::cout << "\nDodela kopiranjem serial3 = serial2" << std::endl;
	std::cout << serial2 << " - " << serial2.getResistance() << std::endl;
	std::cout << serial3 << " - " << serial3.getResistance() << std::endl;

	system("pause");
	return 0;
}
