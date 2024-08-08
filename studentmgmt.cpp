#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    float grade;
};

void displayStudent(const Student& student) {
    cout << "ID: " << student.id << ", Name: " << student.name << ", Grade: " << student.grade << endl;
}

int main() {
    Student students[3];
    int idToSearch, idToUpdate;
    string newName;
    float newGrade;
    int choice;

    // Input student details
    for(int i = 0; i < 3; i++) {
        cout << "Enter ID, Name, and Grade for student " << i+1 << ": ";
        cin >> students[i].id >> students[i].name >> students[i].grade;
    }

    do {
        cout << "\nStudent Management Menu:\n";
        cout << "1. View All Students\n";
        cout << "2. Search Student by ID\n";
        cout << "3. Update Student Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Student Details:\n";
                for(int i = 0; i < 3; i++) {
                    displayStudent(students[i]);
                }
                break;
            case 2:
                cout << "Enter student ID to search: ";
                cin >> idToSearch;
                for(int i = 0; i < 3; i++) {
                    if (students[i].id == idToSearch) {
                        displayStudent(students[i]);
                        break;
                    }
                }
                break;
            case 3:
                cout << "Enter student ID to update: ";
                cin >> idToUpdate;
                for(int i = 0; i < 3; i++) {
                    if (students[i].id == idToUpdate) {
                        cout << "Enter new name and grade: ";
                        cin >> newName >> newGrade;
                        students[i].name = newName;
                        students[i].grade = newGrade;
                        cout << "Student details updated.\n";
                        displayStudent(students[i]);
                        break;
                    }
                }
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
