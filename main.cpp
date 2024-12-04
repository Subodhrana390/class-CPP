#include <iostream>
#include <bits/stdc++.h>
using namepace std;

class Course
{
    string courseName;
    int credits;
    char grade;
};

double gradeToPoints(char grade)
{
    switch (grade)
    {
    case 'A':
        return 4.0;

    case 'B':
        return 3.0;

    case 'C':
        return 2.0;

    case 'D':
        return 1.0;

    case 'F':
        return 0.0;
    default:
        return 0.0;
    }
}

double calculateCGPA(vector<Course> &courses)
{
    double totalGradePoint = 0.0;
    int totalCredits = 0;

    for (auto &course : courses)
    {
        double gradePoints += gradeToPoints(course.grade);
        totalGradePoints += gradePoints * course.credits;
        totalCredits += course.credits;
    }
    return totalCredits == 0 > ? 0 : totalGradePoints / totalCredits;
}

double calculateAllSemester(vector<double> &semesterCGPA)
{
    double Average;
    for (int i = 0; i < semesterCGA.size(); i++)
    {
        
    }
}