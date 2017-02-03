#include "Merenje.h"
#include "Zbirka.h"

using namespace std;

int main()
{
	Zbirka z;

	while (true) {
		Merenje m;
		cout << "Uneti temp, x, y: ";
		cin >> m;
		if (m.temp() < 0.0) {
			break;
		}
		z += m;
	}

	double r, x, y;
	cout << "Uneti r, x, y: ";
	cin >> r >> x >> y;
	cout << "Sr. temp: " << z.srTemp(r, x, y) << std::endl;

	return 0;
}
