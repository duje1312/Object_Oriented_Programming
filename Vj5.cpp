#include<iostream>
#include<string>
#include<cstdlib> 
#include<ctime>
#include<vector>
using namespace std;

class Karta {
public:
	int broj;       
	string zog;    

	Karta(int b, string z) : broj(b), zog(z) {}

	void ispisi() const {
		cout << broj << " od " << zog <<" ";
	}
};
class Mac {
private:
	vector<Karta> karte;
public:
	Mac() {
		string zog[4] = { "Kupe","Dinari","Spade","Bati" };
		for (int i = 0;i < 4;i++) {
			for (int broj = 1;broj <= 10;broj++) {
				karte.emplace_back(broj, zog[i]);

			}
		}
	}
	void promijesaj() {
		srand((unsigned)time(0));
		for (int i = 0; i < karte.size(); ++i) {
			int j = rand() % karte.size();
			swap(karte[i], karte[j]);
		}
	}
	vector<Karta> podijeli(int brojKarata) {
		vector<Karta> ruka;
		for (int i = 0;i < brojKarata;i++) {
			ruka.push_back(karte.back());
			karte.pop_back();
		}
		return ruka;
	}
	
};
class Igrac {
private:
	string ime;
	vector<Karta> ruka;
	int bodovi;
public:
	Igrac(string i) : ime(i), bodovi(0) {}
	void primiKarte(const vector<Karta>& karte) {
		ruka = karte;
	};
	void ispisiRuku() {
		cout << ime << "Karte: ";
		for (const auto& karta : ruka) {
			karta.ispisi();
			
		}
		cout << endl;
	}
	void izracunajAkuzu() {
		bodovi = 0;
		int zog[4][10] = { 0 };
		for (const auto& karta : ruka) {
			int zogIndex = 0;
			if (karta.zog == "Spade")zogIndex = 0;
			else if (karta.zog == "Kupe")zogIndex = 1;
			else if (karta.zog == "Dinari")zogIndex = 2;
			else zogIndex = 3;
			zog[zogIndex][karta.broj - 1]++;

		}
		for (int i = 0;i < 4;i++) {
			if (zog[i][0] > 0 && zog[i][1] > 0 && zog[i][2] > 0)
				bodovi += 3;
		}
		int jedinica = 0, dvojka = 0, trojka = 0;
		for (const auto& karta : ruka) {
			if (karta.broj == 1) {
				jedinica++;
			}
			if (karta.broj == 2) {
				dvojka++;
			}
			if (karta.broj == 3) {
				trojka++;
			}
		}
			if (jedinica >= 3) {
				bodovi += 3;
			}
			if (dvojka >= 3) {
				bodovi += 3;
			}
			if (trojka >= 3) {
				bodovi += 3;
			}
	}
	int dajBodove() {
		return bodovi;
	}
	string dajIme() {
		return ime;
	}
};





int main(void) {
	int broj_igraca;
	cout << "unesi broj igraca (mora biti 2 ili 4)";
	cin >>broj_igraca;
	while (broj_igraca != 2 && broj_igraca != 4) {
		cout << "pogresan broj igraca";
		cin >> broj_igraca;
	}
	vector<Igrac> igraci;
	for (int i = 0;i < broj_igraca;i++) {
		string ime;
		cout << "unesi ime: ";
		cin >> ime;
		igraci.emplace_back(ime);
	}
	Mac mac;
	mac.promijesaj();
	for (auto& igrac : igraci) {
		igrac.primiKarte(mac.podijeli(10));
		igrac.ispisiRuku();
		igrac.izracunajAkuzu();
	}
	cout << "Akuze:" << endl;
	for (auto& igrac : igraci) {
		cout << igrac.dajIme() << ": " << igrac.dajBodove() << " bodova" << endl;
	}
	return 0;
}