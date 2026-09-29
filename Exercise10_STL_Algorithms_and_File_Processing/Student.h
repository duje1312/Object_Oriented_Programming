#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

namespace student_records {

    class Student {
    protected:
        std::string ime;
        std::string prezime;
        double bodovi;

    public:
        Student() : ime(""), prezime(""), bodovi(0.0) {}
        Student(std::string ime, std::string prezime, double bodovi);

        std::string getPrezime() const { return prezime; }
        double getBodovi() const { return bodovi; }
        void setBodovi(double b) { bodovi = b; }

        friend std::istream& operator>>(std::istream& is, Student& s);
        friend std::ostream& operator<<(std::ostream& os, const Student& s);
    };

   
    bool usporedi_prezime(const Student& a, const Student& b);

} 
#endif

