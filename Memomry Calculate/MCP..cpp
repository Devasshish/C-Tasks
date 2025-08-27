#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------- Template Class ----------------
template <class T>
class StudentInfo {
//----------------- Private data members ----------
    T rollNo;
    string fullName;

public:
    StudentInfo(T r, string n) {
        rollNo = r;
        fullName = n;
    }

    T getRollNo() const {
        return rollNo;
    }

    string getFullName() const {
        return fullName;
    }

    void showDetails() const {
        cout << "Roll No: " << rollNo << " | Name: " << fullName << endl;
    }
};

// ---------------- Global List ----------------
vector<StudentInfo<int> > studentList;

// ---------------- Operations ----------------
void insertStudent(int rollNo, const string& name) {
    studentList.emplace_back(rollNo, name);
    cout << "? Student inserted successfully.\n";
}

void viewStudents() {
    if (studentList.empty()) {
        cout << "? No student records available.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    for (const auto& s : studentList) {
        s.showDetails();
    }
    cout << "------------------------\n";
}

void findStudent(int rollNo) {
    for (const auto& s : studentList) {
        if (s.getRollNo() == rollNo) {
            cout << "?? Student found:\n";
            s.showDetails();
            return;
        }
    }
    cout << "? No student with Roll No " << rollNo << " found.\n";
}

void deleteStudent(int rollNo) {
    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if (it->getRollNo() == rollNo) {
            studentList.erase(it);
            cout << "?? Student with Roll No " << rollNo << " removed.\n";
            return;
        }
    }
    cout << "? No student with Roll No " << rollNo << " exists.\n";
}

// ---------------- Main Program ----------------
int main() {
    int option;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Insert Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        int roll;
        string name;

        switch (option) {
            case 1:
                cout << "Enter Roll No: ";
                cin >> roll;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                insertStudent(roll, name);
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                cout << "Enter Roll No to search: ";
                cin >> roll;
                findStudent(roll);
                break;

            case 4:
                cout << "Enter Roll No to delete: ";
                cin >> roll;
                deleteStudent(roll);
                break;

            case 5:
                cout << "?? Exiting program. Goodbye!\n";
                break;

            default:
                cout << "? Invalid option. Please try again.\n";
        }

    } while (option != 5);

    return 0;
}

