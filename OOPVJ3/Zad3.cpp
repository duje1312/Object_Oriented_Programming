#include<iostream>

using namespace std;



int main(void) {

	auto broj = [](int x) {
		if (x % 2 == 0) {
			cout << "paran\n";
		}
		else {
			cout << "nepar\n";
		}
		};
	broj(6);
	broj(7);

	auto prepolovi =[](int x) {
		return x / 2;
	};
	auto udvostruci = [](int x) {
		return x * 2;
		};
	cout << prepolovi(4)<<"\n";
	cout << udvostruci(6)<<"\n";
	int suma = 0;
	auto dodavanjeusumu = [&](int x) {
		suma = suma + x;
		};
	dodavanjeusumu(10);
	cout <<"prva suma: "<< suma << "\n";
	dodavanjeusumu(12);
	cout <<"druga suma: " << suma << "\n";
	int suma2 = 1;
	auto dodavanjeprodukta = [&](int x) {
		return suma2 = suma2 * x;
		};
	dodavanjeprodukta(7);
	cout << "prva suma: " << suma2 << "\n";
	dodavanjeprodukta(10);
	cout << "druga suma: " << suma2 << "\n";

	int suma3=0;
	int prag=5;
	auto dodajpragusumu = [prag, &suma3](int x) {
		if (x > prag) {
			return suma3 = suma3 + x;
		}
		else {
			cout << "mali broj\n";
		}

		};
	cout<<dodajpragusumu(7)<<"\n";
	dodajpragusumu(4);

	int niz[13]={1,2,3,4,5,6,7,8,10,11,12,13,14};
	auto fukniz = [&niz]() {
		for (auto& i : niz) {
			if (i % 2 == 0) {
				i=i / 2;
			}
			else{
				i=i * 2;
			}
		}
		};
	fukniz();
	for (auto& i : niz) {
		cout << i<< " ";
	}
	cout << "\n";
	int suman=0;
	auto sumaniz = [&niz,&suman]() {
		for (auto& i : niz) {
			 suman+= i;
		}
	};
	int niz2[13] = { 1,2,3,4,5,6,7,8,10,11,12,13,14 };
	sumaniz();
	cout <<"suma niza "<< suman<<"\n";
	int prodn = 1;
	auto produktniza = [&niz2, &prodn]() {
		for (auto& i : niz2) {
			prodn = prodn* i;
		}
	};
	produktniza();
	cout <<"produkt niza "<< prodn<<"\n";
	int sumapraga = 0;
	auto pragniza = [&niz2, &sumapraga](int x) {
		for (auto& i : niz2) {
			if (i < x) {
			}
			else {
				sumapraga = sumapraga + i;
			}
		}
	};
	pragniza(10);
	cout << "suma praga " << sumapraga << endl;


	return 0;

}