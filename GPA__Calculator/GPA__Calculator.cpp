// GPA__Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {

    cout << "--------------------------------------------------------------------------" << endl;
    cout << "                             GPA Calculator                               " << endl;
    cout << "--------------------------------------------------------------------------\n" << endl;
    cout << "        Instructions:" << endl;
    cout << "   1. Make sure to enter the right data type" << endl;
    cout << "   2. Make sure to enter Courses and Grades in the same order" << endl;
    cout << "   3. Any mistake in entering the values may result in program terminating                                                          " << endl;
    cout << "                                                                          " << endl;
    cout << "                             Made by Memo                                 " << endl;
    cout << "                               Have Fun!                                  " << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    int CH = 0, P = 0, n = 0; double TQP = 0, TCH = 0; string m, C;
    
    cout << "Enter number of Courses:" << endl;
    cin >> n;
    cout << "Enter your courses:" << endl;
    vector<string> Courses(0);
    //Reading Courses from the User
    for (int i = 0; i < n; i++) {
        cin >> C;
        Courses.push_back(C);
    }
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Enter credit Hours for Each Course: " << endl;
    vector<double> creditHours(0);
    // Reading Credit Hours From the User
    for (int i = 0; i < n; i++) {
        cin >> CH;
        creditHours.push_back(CH);
    }
    cout << "--------------------------------------------------------------------------" << endl;
    // Printing Courses and Credit Hours
    for (int i = 0; i < n; i++) {
        cout << Courses.at(i)<< "\t\t|\t\t" << creditHours.at(i) << endl;
    }
    vector<string> grades(0);
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Enter your Grades in Capital ex: A, B, etc..." << endl;
    for (int i = 0; i < n; i++) {
        cin >> m;
        grades.push_back(m);
    }

    vector<double> points(0);
    for (int i = 0; i < n; i++) {
        if (grades.at(i) == "A") {
            points.push_back(4);
        }
        else if (grades.at(i) == "B") {
            points.push_back(3);
        }
        else if (grades.at(i) == "C") {
            points.push_back(2);
        }
        else if (grades.at(i) == "D") {
            points.push_back(1);
        }
        else if (grades.at(i) == "F") {
            points.push_back(0);
        }
    }
    // Quality points for each subject
    vector<double> qualityPoints(0);
    for (int i = 0; i < n; i++) {
        qualityPoints.push_back(creditHours.at(i) * points.at(i));
    }
    // calculating the sum of qualityPoints
    for (int i = 0; i < n; i++) {
        TQP = TQP + qualityPoints.at(i);
    }

    // calculating the sum of creditHours
    for (int i = 0; i < n; i++) {
        TCH = TCH + creditHours.at(i);
    }

    // Calculating the GPA
    double GPA = TQP / TCH;

    cout << "--------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << Courses.at(i) << "\t\t|\t\t" << creditHours.at(i) << "\t\t|\t\t" << grades.at(i) << endl;
    }
    cout << "\t\t\t\t\t\t\t\t\t" << "Your GPA: " << GPA << endl;

    return 0;
}
