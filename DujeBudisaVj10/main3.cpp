#include "student.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;
using student_records::Student;

int bodovi_u_ocjenu(double bodovi) {
    if (bodovi < 40) return 1;
    else if (bodovi < 55) return 2;
    else if (bodovi < 70) return 3;
    else if (bodovi < 85) return 4;
    else return 5; 
}

Student mapiraj_u_ocjenu(Student s) {
    s.setBodovi(static_cast<double>(bodovi_u_ocjenu(s.getBodovi())));
    return s;
}
bool manje_od_40(const Student& s) {
    return s.getBodovi() < 40;
}
bool usporedi_prezime(const Student& a, const Student& b) {
    return a.getPrezime() < b.getPrezime();
}
double zbroji_ocjene(double suma, const Student& s) {
    return suma + s.getBodovi();
}




int main() {

    ifstream fin("studenti.txt");
    if (!fin) {
        cout << "nije moguce otvorit txt" << endl;
        return 1;
    }

    vector<Student> studenti{ istream_iterator<Student>(fin), istream_iterator<Student>() };
    studenti.erase(remove_if(studenti.begin(), studenti.end(), manje_od_40), studenti.end());
    transform(studenti.begin(), studenti.end(),studenti.begin(),mapiraj_u_ocjenu);
    double suma = accumulate(studenti.begin(), studenti.end(),0.0, zbroji_ocjene);
    double prosjek = 0.0;
    if (!studenti.empty()) {
         prosjek = suma / studenti.size();
    }
    sort(studenti.begin(), studenti.end(), usporedi_prezime);
    cout << "IZVJESTAJ" << endl;
    cout << "------------------------" << endl;
    cout << "Broj studenata: " << studenti.size() << endl;
    cout << "Prosjek ocjena: " << prosjek << endl;
    cout << "------------------------" << endl;
    for (auto& s : studenti) {
        cout << s << endl;
    }

    return 0;
}
