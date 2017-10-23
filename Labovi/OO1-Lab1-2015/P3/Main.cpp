#include "Race.h" // Uključuje sa sobom i Racer.h i Time.h

#include <climits> // UINT_MAX

using namespace std; // U main fajlu je ovo ok pisati

int main()
{
	Racer r1("Marko Misic"), r2("Zivojin Sustran"), r3("Milo Tomasevic");
	r1.time({1, 28, 14}); // Koristi se inicijalizatorska lista
	r2.time({0, 41, 9});
	r3.time({UINT_MAX, UINT_MAX, UINT_MAX});

	Racer r4("Zivojin Misic");
	r4.time(r2.time().plus(r1.time()));

	Race race(4);
	cout << race.add(r1) << ' ';
	cout << race.add(r2) << ' ';
	cout << race.add(r3) << ' ';
	cout << race.add(r4) << ' ';
	cout << race.add(r4) << endl;
	race.write();
	
	return 0;
}
