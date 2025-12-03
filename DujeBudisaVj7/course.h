#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string name;
    string code;
    int ects;

public:
    Course();  // default konstruktor
    Course(string name, string code, int ects);

    // getteri
    string get_name() const;
    string get_code() const;
    int get_ects() const;

    // friend operatori
    friend ostream& operator<<(ostream& os, const Course& course);
    friend istream& operator>>(istream& is, Course& course);
};

#endif
