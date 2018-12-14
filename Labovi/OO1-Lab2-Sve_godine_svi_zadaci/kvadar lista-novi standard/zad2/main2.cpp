#include "Skup.h"
#include "Lista.h"
#include "kvadar.h"
#include <iostream>

void main(){
	int izbor;
	do {	
		Lista lis;
		Skup sk;

		while (true) {
			int a,b,c;
			cout<<"Unesi dimenzije sledeceg kvadra:"<<endl;
			cin>>a>>b>>c;
		if (a < 0 || b < 0 || c < 0) break;
			Kvadar k(a,b,c);
			lis += k;
			sk += k;
		}

		cout<<lis<<endl;
		cout<<sk<<endl;

		cout << "Jos (1/0)?";
		cin >> izbor;
	} while (izbor != 0);
}