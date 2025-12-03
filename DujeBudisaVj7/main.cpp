#include "student.h"
#include "course.h"
#include "universityconstants.h"
#include "studentoffice.h"
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<Student> studenti;
    int n;

    cout << "Trenutno studenata: " << Student::get_total_students() << endl;
    cout << "Koliko studenata zelite unijeti: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        Student s(0, "", "", 0);

        cout << "Upisite redom: ID Ime Program Godina" << endl;
        cin >> s;

        // svaki student automatski upisuje jedan kolegij radi testiranja
        Course c1("Matematika", "MAT101", 6);
        s += c1;  // operator +=

        studenti.push_back(s);  
    }

    // prolaz kroz sve studente
    for (Student& s : studenti) {

        cout << "\n--- PODACI O STUDENTU ---\n";
        cout << s << endl;

        // POLAGANJE KOLEGIJA
        if (s.get_year() > 0 && true) {
            s.complete_course(0);
        }

        // PROVJERA POVECANJA GODINE
        ++s;  // operator ++ (prefiks)

        cout << "\nNakon polaganja i provjere godine:\n";
        cout << s << endl;
    }

    cout << "\nTrenutno studenata u programu: "
        << Student::get_total_students() << endl;

    // PRIKAZ UNIVERSITETSKIH PRAVILA
    cout << "\n--- Univerzitetska pravila ---\n";
    UniversityConstants::print_university_rules();

    // TEST UNOSA KOLEGIJA
    cout << "\nUnesite novi kolegij:\n";
    Course c;
    cin >> c;

    cout << "\nUneseni kolegij:\n";
    cout << c;
    StudentOffice office;

    // 1. move student na novi smjer
    studenti[0] = office.moveStudent(std::move(studenti[0]), "Informatika");

    // 2. upisi novi kolegij kroz StudentOffice
    Course c2("Fizika", "FIZ103", 5);
    office.enroll_student(studenti[0], c2);

    // 3. polaganje ispita
    office.process_exam_results(studenti[0], 0);

    // 4. update godina
    office.update_student_years(studenti);W

    return 0;
}
