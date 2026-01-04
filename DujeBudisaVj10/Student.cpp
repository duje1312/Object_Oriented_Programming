#include"student.h"

using namespace std;

namespace student_records{

Student::Student(string ime, string prezime, double bodovi):ime(ime), prezime(prezime), bodovi(bodovi) {}

istream& operator>>(istream& is, Student& s) {
	return is >> s.ime >> s.prezime >> s.bodovi;
}

ostream& operator<<(ostream& os,const Student& s) {
    os << s.ime << " " << s.prezime << " " << s.bodovi;
    return os;
}
bool usporedi_prezime(const Student& a, const Student& b) {
    return a.getPrezime() < b.getPrezime();
}

}

