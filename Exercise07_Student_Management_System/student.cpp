#include "student.h"
#include "universityconstants.h"
#include<iostream>
using namespace std;

int Student::total_students = 0;

// Konstruktor
Student::Student(int id, string name, string study_prog, int year)
    : id(id), name(name), study_prog(study_prog), year(year),
    enrolled_courses(nullptr), enrolled_count(0),
    completed_courses(nullptr), completed_count(0)
{
    total_students++;
}

// COPY konstruktor
Student::Student(const Student& other)
{
    id = other.id;
    name = other.name;
    study_prog = other.study_prog;
    year = other.year;

    enrolled_count = other.enrolled_count;
    completed_count = other.completed_count;

    enrolled_courses = new Course[enrolled_count];
    for (size_t i = 0; i < enrolled_count; i++)
        enrolled_courses[i] = other.enrolled_courses[i];

    completed_courses = new Course[completed_count];
    for (size_t i = 0; i < completed_count; i++)
        completed_courses[i] = other.completed_courses[i];

    total_students++;
}

// MOVE konstruktor
Student::Student(Student&& other) noexcept
{
    id = other.id;
    name = move(other.name);
    study_prog = move(other.study_prog);
    year = other.year;

    enrolled_courses = other.enrolled_courses;
    enrolled_count = other.enrolled_count;

    completed_courses = other.completed_courses;
    completed_count = other.completed_count;

    other.enrolled_courses = nullptr;
    other.completed_courses = nullptr;
    other.enrolled_count = 0;
    other.completed_count = 0;

    total_students++;
}

// COPY =
Student& Student::operator=(const Student& other)
{
    if (this == &other) return *this;

    delete[] enrolled_courses;
    delete[] completed_courses;

    id = other.id;
    name = other.name;
    study_prog = other.study_prog;
    year = other.year;

    enrolled_count = other.enrolled_count;
    completed_count = other.completed_count;

    enrolled_courses = new Course[enrolled_count];
    for (size_t i = 0; i < enrolled_count; i++)
        enrolled_courses[i] = other.enrolled_courses[i];

    completed_courses = new Course[completed_count];
    for (size_t i = 0; i < completed_count; i++)
        completed_courses[i] = other.completed_courses[i];

    return *this;
}

// MOVE =
Student& Student::operator=(Student&& other) noexcept
{
    if (this == &other) return *this;

    delete[] enrolled_courses;
    delete[] completed_courses;

    id = other.id;
    name = move(other.name);
    study_prog = move(other.study_prog);
    year = other.year;

    enrolled_courses = other.enrolled_courses;
    enrolled_count = other.enrolled_count;

    completed_courses = other.completed_courses;
    completed_count = other.completed_count;

    other.enrolled_courses = nullptr;
    other.completed_courses = nullptr;
    other.enrolled_count = 0;
    other.completed_count = 0;

    return *this;
}

// Destruktor
Student::~Student()
{
    delete[] enrolled_courses;
    delete[] completed_courses;
    total_students--;
}

// Upis kolegija
void Student::enroll_course(const Course& c)
{
    Course* novo = new Course[enrolled_count + 1];
    for (size_t i = 0; i < enrolled_count; i++)
        novo[i] = enrolled_courses[i];

    novo[enrolled_count] = c;

    delete[] enrolled_courses;
    enrolled_courses = novo;
    enrolled_count++;
}

// Polaganje kolegija
void Student::complete_course(size_t index)
{
    if (index >= enrolled_count) return;

    Course passed = enrolled_courses[index];

    Course* newC = new Course[completed_count + 1];
    for (size_t i = 0; i < completed_count; i++)
        newC[i] = completed_courses[i];
    newC[completed_count] = passed;

    delete[] completed_courses;
    completed_courses = newC;
    completed_count++;

    Course* newE = new Course[enrolled_count - 1];
    for (size_t i = 0, j = 0; i < enrolled_count; i++)
        if (i != index)
            newE[j++] = enrolled_courses[i];

    delete[] enrolled_courses;
    enrolled_courses = newE;
    enrolled_count--;
}

// operator +=
Student& Student::operator+=(const Course& c)
{
    enroll_course(c);
    return *this;
}

// operator ++ prefiks
Student& Student::operator++()
{
    int ects_total = 0;
    for (size_t i = 0; i < completed_count; i++)
        ects_total += completed_courses[i].get_ects();
    if (ects_total >= UniversityConstants::REQUIRED_ECTS_PER_YEAR){
        year++;
    }
    return *this;
}

// operator ++ postfiks
Student Student::operator++(int)
{
    Student temp = *this;
    ++(*this);
    return temp;
}

int Student::get_id() { return id; }
string Student::get_name() { return name; }
string Student::get_study() { return study_prog; }
int Student::get_year() { return year; }
int Student::get_total_students() { return total_students; }

ostream& operator<<(ostream& os, Student& s)
{
    os << "Student: " << s.name << " (" << s.id << ")\n";
    os << "Upisani kolegiji:\n";
    for (size_t i = 0; i < s.enrolled_count; i++)
        os << " - " << s.enrolled_courses[i] << "\n";

    os << "Polozeni kolegiji:\n";
    for (size_t i = 0; i < s.completed_count; i++)
        os << " + " << s.completed_courses[i] << "\n";

    return os;
}

istream& operator>>(istream& is, Student& student)
{
    is >> student.id >> student.name >> student.study_prog >> student.year;
    return is;
}

