// Lab1_part1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Datastrukturer och algoritmer vt 20

#include "Lab1_part1.h"

class Student;
class Course;

void PrintMainMenu();
void ViewStudents(list<Student> &sl);
void InsertStudent(list<Student>& sl);
void ViewStudentsLinkedList(DoublyLinkedList& dllc);
void InsertStudentLinkedList(DoublyLinkedList& dllc);

int main()
{
    bool exit = false;
    list<Student> studentlist;
    int choice = 0;
    DoublyLinkedList dllc;

/*
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
    */
    while (choice != 4)
    {
        PrintMainMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            InsertStudentLinkedList(dllc);
            break;
        case 2:
            break;
        case 3:
            ViewStudentsLinkedList(dllc);
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

void InsertStudentLinkedList(DoublyLinkedList& dllc)
{
    string name;
    int choise = 0;
    string coursename;
    float credit;
    int grade;
    Course* newCourse;
    Node* node;
    NodeCourse* nodecourse;

    cout << "Name:";
    cin >> name;
    //Student* newStudent = new Student();
    //newStudent->name = name;
    node = new Node();
    node->name = name;
    dllc.addtail(node);


    while (choise != 4)
    {
        cout << "Course name :";
        cin >> coursename;
        cout << "Course credit :";
        cin >> credit;
        cout << "Course grade :";
        cin >> grade;

        /*newCourse = new Course();
        newCourse->name = coursename;
        newCourse->credit = credit;
        newCourse->grade = grade;*/

        //newStudent->courselist.push_back(*newCourse);

        nodecourse = new NodeCourse();
        nodecourse->credit = credit;
        nodecourse->grade = grade;
        nodecourse->name = coursename;

        node->dllcourse->addtail(nodecourse);

        cout << "Continue (4 Exit) :";
        cin >> choise;

    }

    //sl.push_back(*newStudent);
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

void ViewStudentsLinkedList(DoublyLinkedList & dllc)
{
 /*   list<Student>::iterator it;

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
 */
    dllc.display_forward();
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node* current, * currentDel;

    current = head->next;


    while (current != tail)
    {
        currentDel = current;
        current = current->next;

        delete currentDel;
    }


    delete head;
    delete tail;
}

DoublyLinkedList::DoublyLinkedList()
{
    head = new Node();
    tail = new Node();

    head->nodeNumber = 0;

    head->prev = nullptr;
    head->next = tail;

    tail->nodeNumber = -1;

    tail->next = nullptr;
    tail->prev = head;

    numberofnodes = 0;

}

bool DoublyLinkedList::addtail(Node* data)
{
    data->nodeNumber = tail->prev->nodeNumber + 1;

    data->prev = tail->prev;
    data->next = tail;

    data->prev->next = data;
    tail->prev = data;

    cout << "Data : " << data->data << endl;

    numberofnodes++;

    return true;
}

bool DoublyLinkedList::add(Node* data, int pos)
{
    Node* current;
    int currentindex;

    currentindex = 1;
    current = head->next;

    if (pos > numberofnodes + 1)
        return false;
    else if (pos == numberofnodes + 1)
    {
        data->nodeNumber = tail->prev->nodeNumber + 1;

        data->prev = tail->prev;
        data->next = tail;

        data->prev->next = data;
        tail->prev = data;
    }
    else
    {

        while (currentindex != pos)
        {
            current = current->next;
            currentindex++;
        }

        data->prev = current->prev;
        data->next = current;
        data->prev->next = data;
        current->prev = data;

    }

    numberofnodes++;
    cout << "Data : " << data->data << endl;
    return true;
}

bool DoublyLinkedList::remove(int pos)
{
    Node* current;
    int currentindex;

    if (pos > numberofnodes)
        return false;

    currentindex = 1;
    current = head->next;

    while (currentindex != pos)
    {
        current = current->next;
        currentindex++;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;

    return true;
}

bool DoublyLinkedList::replace(Node* oldnode, Node* newnode)
{
    newnode->next = oldnode->next;
    newnode->prev = oldnode->prev;
    oldnode->prev->next = newnode;
    oldnode->next->prev = newnode;

    delete oldnode;
    return true;
}

void DoublyLinkedList::display_forward()
{
    Node* current;
    NodeCourse* coursecurrent;

    current = head->next;

    while (current != tail)
    {
        //cout << "Data for node nr: " << current->nodeNumber << " is: " << current->data << endl;
        cout << "Student name:" << current->name << endl;

        current->dllcourse->display_forward();


        current = current->next;
    }
}

void DoublyLinkedList::display_backward()
{
    Node* current;

    current = tail->prev;

    while (current != head)
    {
        cout << "Data for node nr: " << current->nodeNumber << " is: " << current->data << endl;
        current = current->prev;
    }
}

Node::Node()
{
    
    dllcourse = new DoublyLinkedListCourse();
}

Node::~Node()
{
    dllcourse->~DoublyLinkedListCourse();
}

DoublyLinkedListCourse::~DoublyLinkedListCourse()
{
    NodeCourse* current, * currentDel;

    current = head->next;


    while (current != tail)
    {
        currentDel = current;
        current = current->next;

        delete currentDel;
    }


    delete head;
    delete tail;
}

DoublyLinkedListCourse::DoublyLinkedListCourse()
{
    head = new NodeCourse();
    tail = new NodeCourse();

    head->nodeNumber = 0;

    head->prev = nullptr;
    head->next = tail;

    tail->nodeNumber = -1;

    tail->next = nullptr;
    tail->prev = head;

    numberofnodes = 0;

}

bool DoublyLinkedListCourse::addtail(NodeCourse* data)
{
    data->nodeNumber = tail->prev->nodeNumber + 1;

    data->prev = tail->prev;
    data->next = tail;

    data->prev->next = data;
    tail->prev = data;

    cout << "Data : " << data->data << endl;

    numberofnodes++;

    return true;
}

bool DoublyLinkedListCourse::add(NodeCourse* data, int pos)
{
    NodeCourse* current;
    int currentindex;

    currentindex = 1;
    current = head->next;

    if (pos > numberofnodes + 1)
        return false;
    else if (pos == numberofnodes + 1)
    {
        data->nodeNumber = tail->prev->nodeNumber + 1;

        data->prev = tail->prev;
        data->next = tail;

        data->prev->next = data;
        tail->prev = data;
    }
    else
    {

        while (currentindex != pos)
        {
            current = current->next;
            currentindex++;
        }

        data->prev = current->prev;
        data->next = current;
        data->prev->next = data;
        current->prev = data;

    }

    numberofnodes++;
    cout << "Data : " << data->data << endl;
    return true;
}

bool DoublyLinkedListCourse::remove(int pos)
{
    NodeCourse* current;
    int currentindex;

    if (pos > numberofnodes)
        return false;

    currentindex = 1;
    current = head->next;

    while (currentindex != pos)
    {
        current = current->next;
        currentindex++;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;

    return true;
}

bool DoublyLinkedListCourse::replace(NodeCourse* oldnode, NodeCourse* newnode)
{
    newnode->next = oldnode->next;
    newnode->prev = oldnode->prev;
    oldnode->prev->next = newnode;
    oldnode->next->prev = newnode;

    delete oldnode;
    return true;
}

void DoublyLinkedListCourse::display_forward()
{
    NodeCourse* current;
    current = head->next;

    while (current != tail)
    {
        //cout << "Data for node nr: " << current->nodeNumber << " is: " << current->data << endl;
        cout << "Course name:" << current->name << endl;
        cout << "Course credit:" << current->credit << endl;
        cout << "Course grade:" << current->grade << endl;
        current = current->next;
    }
}

void DoublyLinkedListCourse::display_backward()
{
    NodeCourse* current;

    current = tail->prev;

    while (current != head)
    {
        cout << "Data for node nr: " << current->nodeNumber << " is: " << current->data << endl;
        current = current->prev;
    }
}

NodeCourse::NodeCourse()
{

}