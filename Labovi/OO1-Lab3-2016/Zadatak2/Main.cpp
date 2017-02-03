#include "Artikal.h"
#include "Paket.h"

using namespace std;

Roba* dijalog()
{
	cout << "Uneti tip robe: ";
	char c;
	cin >> c;
	
	switch (c) {
	case 'A': case 'a':
		cout << "Uneti oznaku i vrednost: ";
		char ozn;
		double vr;
		cin >> ozn >> vr;
		return new Artikal(ozn, vr);
		break;

	case 'P': case 'p':
		return new Paket();
		break;

	default:
		throw std::runtime_error("Ta roba ne postoji");
		// drugi nacin: return nullptr;
	}
}


int main() try // try-catch za celu f-ju, nije obavezan ali je dobra fora
{
	Paket p;
	while (true) {
		auto r = dijalog();
		p += *r;
		delete r;
		cout << p << endl;
	}
	return 0;
} catch (...) {
	return 1;
}

/* drugi nacin, vrv bolji */
//int main()
//{
//	Paket p;
//	Roba *r;
//	while ((r = dijalog()) != nullptr) {
//		p += *r;
//		cout << p << endl;
//	}
//	return 0;
//}
