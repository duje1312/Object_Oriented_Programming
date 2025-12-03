#ifndef STUDENTOFFICE_H
#define STUDENTOFFICE_H

#include "student.h"
#include "course.h"
#include "universityconstants.h"
#include <vector>
using namespace std;

class StudentOffice {
public:
    // PREBACIVANJE STUDENTA NA NOVI SMJER (move semantika)
    Student moveStudent(Student&& s, const string& new_program);

    // UPIS KOLEGIJA UZ LIMIT ECTS
    bool enroll_student(Student& s, const Course& c);

    // POLAGANJE KOLEGIJA
    void process_exam_results(Student& s, size_t index);

    // POVECANJE GODINE SVIM STUDENTIMA
    void update_student_years(vector<Student>& studenti);
};

#endif
