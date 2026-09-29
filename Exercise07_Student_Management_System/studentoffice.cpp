#include "studentoffice.h"

// MOVE STUDENT – mijenjanje studijskog programa
Student StudentOffice::moveStudent(Student&& s, const string& new_program)
{
    Student temp = std::move(s);
    // promjena smjera
    temp.study_prog = new_program;
    return temp;
}

bool StudentOffice::enroll_student(Student& s, const Course& c)
{
    int currentECTS = 0;

    // izraèun trenutnih ECTS bodova
    for (size_t i = 0; i < s.enrolled_count; i++)
        currentECTS += s.enrolled_courses[i].get_ects();

    if (currentECTS + c.get_ects() > UniversityConstants::MAX_ETCS_PER_YEAR)
        return false;

    s += c; // koristi operator +=
    return true;
}

void StudentOffice::process_exam_results(Student& s, size_t index)
{
    s.complete_course(index);
}

void StudentOffice::update_student_years(vector<Student>& studenti)
{
    for (Student& s : studenti)
        ++s;   // koristi tvoj prefix operator++
}
