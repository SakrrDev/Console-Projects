/*
    Student Management System
    Paradigm: Procedural Programming
    Features:
    - Add Student
    - Display Students
    - Search Student
    - Update Student
    - Delete Student
    - Sort by Name / Grade
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct student
{
    string name;
    int id;
    char grade;
};

vector<student> students;

// functions
bool addStudent(string name, int id, char grade);    // case 1
void displayStudents();                              // case 2
void searchStudent(int id);                          // case 3
void updateStudent(int id);                          // case 4
void deleteStudent(int id);                          // case 5
void sortByGrade();                                  // case 6
void sortByName();                                   // case 7

int main()
{
    cout << "===== Welcome in Student Management System =====\n";
    int choice;

    do
    {
        cout << "please choice a operator (0 to 7)\n";
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Updating Student" << endl;
        cout << "5. Deleting Student" << endl;
        cout << "6. Sorting by grade" << endl;
        cout << "7. Sorting by name" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Add Student:" << endl;

            string name;
            int id;
            char grade;

            cout << "Student Full Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Student ID: ";
            cin >> id;

            cout << "Student grade: ";
            cin >> grade;

            bool ok = addStudent(name, id, grade);

            if (ok)
                cout << "Student " << name << " is successfully Added!" << endl;
            else
                cout << "ID already exists!" << endl;

            cout << endl;
        }
        break;

        case 2:
            cout << "Display Students:" << endl;
            displayStudents();
            cout << endl;
            break;

        case 3:
        {
            cout << "Search Student:" << endl;
            int _ID;
            cout << "Enter Student ID: ";
            cin >> _ID;
            searchStudent(_ID);
            cout << endl;
        }
        break;

        case 4:
        {
            cout << "Updating Student:" << endl;
            int _ID;
            cout << "Enter Student ID: ";
            cin >> _ID;
            updateStudent(_ID);
            cout << endl;
        }
        break;

        case 5:
        {
            cout << "Deleting Student:" << endl;
            int _ID;
            cout << "Enter Student ID: ";
            cin >> _ID;
            deleteStudent(_ID);
            cout << endl;
        }
        break;

        case 6:
            cout << "Sorting by Grade:" << endl;
            sortByGrade();
            cout << endl;
            break;

        case 7:
            cout << "Sorting by Name:" << endl;
            sortByName();
            cout << endl;
            break;

        case 0:
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            cout << endl;
        }

    } while (choice > 0);
}

bool addStudent(string name, int id, char grade)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            return false;
        }
    }

    student s;
    s.name = name;
    s.id = id;
    s.grade = grade;

    students.push_back(s);
    return true;
}

void displayStudents()
{
    if (students.size() == 0)
    {
        cout << "No Students Found!" << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].name << " "
             << students[i].id << " "
             << students[i].grade << endl;
    }
}

void searchStudent(int id)
{
    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << "Student Found: "
                 << students[i].name << " "
                 << students[i].id << " "
                 << students[i].grade << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found." << endl;
}

void updateStudent(int id)
{
    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            found = true;

            cout << "Student Found: "
                 << students[i].name << " "
                 << students[i].id << " "
                 << students[i].grade << endl;

            string name;
            int newId;
            char grade;

            cout << "Enter a new name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter a new id: ";
            cin >> newId;

            cout << "Enter a new grade: ";
            cin >> grade;

            students[i].name = name;
            students[i].id = newId;
            students[i].grade = grade;

            cout << "Student updated successfully." << endl;
            return;
        }
    }

    if (!found)
        cout << "Student not found." << endl;
}

void deleteStudent(int id)
{
    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            found = true;

            cout << "Student Found: "
                 << students[i].name << " "
                 << students[i].id << " "
                 << students[i].grade << endl;

            int option;
            cout << "Are you sure? (1=yes, 0=no): ";
            cin >> option;

            if (option == 1)
            {
                students.erase(students.begin() + i);
                cout << "Deleted successfully." << endl;
            }
            else
            {
                cout << "Cancelled." << endl;
            }

            return;
        }
    }

    if (!found)
        cout << "Student not found." << endl;
}

void sortByGrade()
{
    if (students.empty())
    {
        cout << "No Students Found!" << endl;
        return;
    }

    sort(students.begin(), students.end(),
         [](const student &a, const student &b)
         {
             return a.grade < b.grade;
         });

    cout << "Sorted by grade successfully." << endl;
}

void sortByName()
{
    if (students.empty())
    {
        cout << "No Students Found!" << endl;
        return;
    }

    sort(students.begin(), students.end(),
         [](const student &a, const student &b)
         {
             return a.name < b.name;
         });

    cout << "Sorted by name successfully." << endl;
}