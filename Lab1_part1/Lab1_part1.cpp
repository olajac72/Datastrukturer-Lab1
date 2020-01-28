// Lab1_part1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Datastrukturer och algoritmer

#include <iostream>
#include <list>

using namespace std;

class Student;
class Course;

void PrintMainMenu();
void ViewStudents(list<Student> &sl);
void InsertStudent(list<Student>& sl);


int main()
{
    bool exit = false;
    list<Student> studentlist;
    int choise = 0;

    while (choise != 4)
    {
        PrintMainMenu();
        cin >> choise;
        switch (choise)
        {
        case 1:
            InsertStudent(studentlist);
            break;
        case 2:
            break;
        case 3:
            ViewStudents(studentlist);
            break;
        default:
            break;
        }
    }
}



void PrintMainMenu()
{
    cout << "1 Insert student" << endl;
    cout << "2 Delete student" << endl;
    cout << "3 View students" << endl;
    cout << "4 Exit program" << endl;
}


class Student
{
public:
    string name;
    list<Course> courselist;
};

class Course
{
public:
    string name;
    float credit;
    int grade;
};

void InsertStudent(list<Student>& sl)
{
    string name;
    int choise = 0;
    string coursename;
    float credit;
    int grade;
    Course* newCourse;

    cout << "Name:";
    cin >> name;
    Student* newStudent = new Student();
    newStudent->name = name;
    
    while (choise != 4)
    {
        cout << "Course name :";
        cin >> coursename;
        cout << "Course credit :";
        cin >> credit;
        cout << "Course grade :";
        cin >> grade;

        newCourse = new Course();
        newCourse->name = coursename;
        newCourse->credit = credit;
        newCourse->grade = grade;

        newStudent->courselist.push_back(*newCourse);

        cout << "Continue (4 Exit) :";
        cin >> choise;

    }

    sl.push_back(*newStudent);
}

void ViewStudents(list<Student>& sl)
{
    list<Student>::iterator it;

    for (it = sl.begin(); it != sl.end(); ++it)
    {
        cout << it->name << endl;

        list<Course>::iterator cit;


        for (cit = it->courselist.begin(); cit != it->courselist.end(); ++cit)
        {
            cout << cit->name << endl;
            cout << cit->credit << endl;
            cout << cit->grade << endl << endl;
        }
    }
}