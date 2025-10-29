#include<iostream>
#include<string>
#include<cctype>

using namespace std;


 struct Student {
	string ime;
	int JMBAG;
	int god_stud;
	int ECTS;
	float prosjek;
	





};
 void filter_students(Student studenti[], size_t n,
	 void (*akcija)(Student&),
	 bool (*filter)(Student&)) {
	 for (size_t i = 0; i < n; ++i) {
		 if (filter(studenti[i])) { 
			 akcija(studenti[i]);   
		 }
	 }
 }
 void ispisi(Student& s) {
	 cout << s.ime << " (" << s.JMBAG << "), "
		 << s.god_stud << ". godina, "
		 << s.ECTS << " ECTS, prosjek: "
		 << s.prosjek << endl;
 }

 void povecaj_godinu(Student& s) {
	 s.god_stud++;
 }





int main(void) {
	Student studenti[3];
	studenti[0].ime = "Duje";
	studenti[0].JMBAG = 128000;
	studenti[0].god_stud = 3;
	studenti[0].ECTS = 48;
	studenti[0].prosjek = 4.32;

	studenti[1].ime  = "Mate";
	studenti[1].JMBAG = 123000;
	studenti[1].god_stud = 2;
	studenti[1].ECTS = 18;
	studenti[1].prosjek = 2.32;

	studenti[2].ime = "Marinko";
	studenti[2].JMBAG = 128645;
	studenti[2].god_stud = 4;
	studenti[2].ECTS = 60;
	studenti[2].prosjek = 5;

	size_t n = 3; 

	cout << " Studenti s prosjekom vecim od 3.5:\n";
	filter_students(studenti, n, ispisi, [](Student& s) {
		return s.prosjek > 3.5;
		});

	cout << "\n Studenti s barem 45 ECTS - povecaj godinu:\n";
	filter_students(studenti, n, povecaj_godinu, [](Student& s) {
		return s.ECTS >= 45;
		});

	cout << "\n Nakon povecanja godine:\n";
	for (int i = 0; i < n; i++) ispisi(studenti[i]);

	return 0;
}



