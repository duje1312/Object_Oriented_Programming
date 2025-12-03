#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include "course.h"

using namespace std;

class Student {
private:
    int id;
    string name;
    string study_prog;
    int year;

    Course* enrolled_courses;
    size_t enrolled_count;

    Course* completed_courses;
    size_t completed_count;

    static int total_students;

public:
    Student(int id, string name, string study_prog, int year);
    Student(const Student& other);        
    Student(Student&& other) noexcept;    
    Student& operator=(const Student& other); 
    Student& operator=(Student&& other) noexcept; 
    ~Student();

    void enroll_course(const Course& c);
    void complete_course(size_t index);

    // OPERATORI ZA ZADATAK 6
    Student& operator+=(const Course& c);   
    Student& operator++();                  
    Student operator++(int);                

    int get_id();
    string get_name();
    string get_study();
    int get_year();

    static int get_total_students();

    friend ostream& operator<<(ostream& os, Student& student);
    friend istream& operator>>(istream& is, Student& student);
    friend class StudentOffice;

};






#endif