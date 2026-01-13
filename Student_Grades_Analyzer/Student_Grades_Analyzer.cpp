#include <iostream>
#include <string>
#include <vector>
using namespace std;

int BigDegree(int a, int b , int c){
    // Find Big Degree
    if (a >= b && a >= c){
            return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

void GetStudentInfo()
{
    int numberOfstudents;
    cout << "Enter a Number of Students: ";
    cin >> numberOfstudents;
    
    string studentNames[numberOfstudents] = {};
    int SumStudents[numberOfstudents] = {};
    int AvrStudents[numberOfstudents] = {};
    int Degrees[numberOfstudents] = {};

    for (int i = 0; i < numberOfstudents; i++)
    {
        cout << "Enter a name of student [" << i + 1 << "]" << endl;
        cin >> studentNames[i];

        int First_Subject,Second_Subject,Third_Subject;
        cout << "Enter Student's Degree in First Subject: "; cin >> First_Subject;
        cout << "Enter Student's Degree in Second Subject: "; cin >> Second_Subject;
        cout << "Enter Student's Degree in Third Subject: "; cin >> Third_Subject;

        int sum = First_Subject + Second_Subject + Third_Subject;
        SumStudents[i] = sum;
        int Avarage = sum / 3;
        AvrStudents[i] = Avarage;

        // Find Big Degree
        int Big_Degree = BigDegree(First_Subject,Second_Subject,Third_Subject);

        Degrees[i] = Big_Degree;

       cout << "===============================" << endl;
    }

    // Print Students Info
    for (int i = 0; i < numberOfstudents; i++){
        cout << "Student number [" << i + 1 << "]" << endl;
        cout << "Total Sum is " << SumStudents[i] << endl;
        cout << "Total Avarage is " << AvrStudents[i] << endl;
        cout << "Big Degree is " << Degrees[i] << endl;

        cout << endl; 
    }

    // print a high Student in Degree
    int mx = SumStudents[0];
    int temp = 0;
    for (int i = 0; i < numberOfstudents; i++){
        if (SumStudents[i] > mx){
            mx = SumStudents[i];
            temp = i;
        }
    }

    cout << "High Student in Degree is " << endl;
    cout << studentNames[temp] << endl;
    cout << "Congratulations [" << studentNames[temp] << "]"<< endl;
}

int main()
{

    GetStudentInfo();

    return 0;
}

/*
           _____      _               _____             
         / ____|    | |             |  __ \            
        | (___   __ _| | ___ _ __   | |  | | _____   __
        \___ \ / _` | |/ / | '__|   | |  | |/ _ \ \ / /
        ____) | (_| |   <| | |      | |__| |  __/\ V / 
       |_____/ \__,_|_|\_\_|_|      |_____/ \___| \_/  
 
*/