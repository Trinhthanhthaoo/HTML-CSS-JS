#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    char id[12];
    char name[30];
    char _class[10];
    float mMath;
    float mPhysical;
};

void inputStudent(Student &student) {
    cout << "Enter student ID: ";
    cin.getline(student.id, 12);
    cout << "Enter student name: ";
    cin.getline(student.name, 30);
    cout << "Enter student class: ";
    cin.getline(student._class, 10);
    cout << "Enter student's math grade: ";
    cin >> student.mMath;
    cout << "Enter student's physical grade: ";
    cin >> student.mPhysical;
    cin.ignore();
}

void outputStudent(const Student &student) {
    cout << "ID: " << student.id << endl;
    cout << "Name: " << student.name << endl;
    cout << "Class: " << student._class << endl;
    cout << "Math grade: " << student.mMath << endl;
    cout << "Physical grade: " << student.mPhysical << endl;
}

void searchStudent(const Student *students, int size, const char *id) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(students[i].id, id) == 0) {
            cout << "Student found:" << endl;
            outputStudent(students[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID \"" << id << "\" not found." << endl;
    }
}

float calculateAvg(const Student &student) {
    return (student.mMath + student.mPhysical) / 2.0;
}

bool compareStudents(const Student &student1, const Student &student2) {
    return calculateAvg(student1) > calculateAvg(student2);
}

void sortStudents(Student *students, int size) {
    sort(students, students + size, compareStudents);
}

void inputStudents(Student *students, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Enter information for student " << i + 1 << ":" << endl;
        inputStudent(students[i]);
    }
}

void outputStudents(const Student *students, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Information for student " << i + 1 << ":" << endl;
        outputStudent(students[i]);
        cout << endl;
    }
}

int main() {
    const int SIZE = 3; 
    Student students[SIZE];

    inputStudents(students, SIZE);

    cout << "List of students:" << endl;
    outputStudents(students, SIZE);

    char searchID[12];
    cout << "Enter student ID to search: ";
    cin.getline(searchID, 12);
    searchStudent(students, SIZE, searchID);

    sortStudents(students, SIZE);

    cout << "\nList of students sorted by average grade (descending order):" << endl;
    outputStudents(students, SIZE);

    return 0;
}

