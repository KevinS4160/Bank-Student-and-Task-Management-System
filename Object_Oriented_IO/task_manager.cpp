#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Student {
public:
    int id;
    string name;
    float grade;

    Student(int i, string n, float g) {
        id = i;
        name = n;
        grade = g;
    }

    void displayStudent() {
        cout << "ID: " << id << " | Name: " << name << " | Grade: " << grade << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;
    string filename = "students.txt";

    void loadStudents() {
        ifstream file(filename);
        if (!file) return;

        int id;
        string name;
        float grade;
        while (file >> id) {
            file.ignore();
            getline(file, name);
            file >> grade;
            students.push_back(Student(id, name, grade));
        }
        file.close();
    }

    void saveStudents() {
        ofstream file(filename);
        for (Student s : students) {
            file << s.id << endl << s.name << endl << s.grade << endl;
        }
        file.close();
    }

public:
    StudentManager() { loadStudents(); }

    void addStudent(string name, float grade) {
        int id = students.size() + 1;
        students.push_back(Student(id, name, grade));
        saveStudents();
        cout << "Student Added Successfully!\n";
    }

    void showStudents() {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }
        for (Student s : students) {
            s.displayStudent();
        }
    }
};

int main() {
    StudentManager sm;
    int choice;
    string name;
    float grade;

    while (true) {
        cout << "\n1. Add Student\n2. Show Students\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Student Name: ";
                getline(cin, name);
                cout << "Enter Grade: ";
                cin >> grade;
                sm.addStudent(name, grade);
                break;
            case 2:
                sm.showStudents();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid Choice! Try Again.\n";
        }
    }
}
