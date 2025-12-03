#include "course.h"
using namespace std;

Course::Course() : name(""), code(""), ects(0) {}

Course::Course(string name, string code, int ects)
    : name(name), code(code), ects(ects) {
}

string Course::get_name() const {
    return name;
}

string Course::get_code() const {
    return code;
}

int Course::get_ects() const {
    return ects;
}

ostream& operator<<(ostream& os, const Course& course) {
    os << "Kolegij: " << course.name << "\n"
        << "Sifra: " << course.code << "\n"
        << "ECTS: " << course.ects << "\n";
    return os;
}

istream& operator>>(istream& is, Course& course) {
    cout << "Upisite ime kolegija: ";
    is >> course.name;

    cout << "Upisite sifru kolegija: ";
    is >> course.code;

    cout << "Upisite broj ECTS bodova: ";
    is >> course.ects;

    return is;
}
