#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << a + b << std::endl;

	int sum = 0, i;
	do {
		std::cin >> i;
		sum += i;
	} while (i != 0);
	std::cout << "Zbir je: " << sum << std::endl;

	return 0;
}
