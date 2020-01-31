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
    int choice = 0;
    StudentListTest slt;
    DoublyLinkedList dllc;

    /*bool exit = false;
    list<Student> studentlist;
    
    

    vector<StudentListBase*> slb;

    StudentList* sl = new StudentList();

    slb.push_back(sl);

    StudentLinkedList* sll = new StudentLinkedList();

    slb.push_back(sll);

    slb[0]->print();
    slb[1]->print();*/

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
            slt.generateTest();
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

void StudentListTest::generateTest()
{
    char tkn1, tkn2, tkn3;
    int grade, credit;
    string name;
    Student* student;
    Course* course;
    unsigned int seed;

    DoublyLinkedList* dll;
    Node* node;
    DoublyLinkedListCourse* dllc;
    NodeCourse* nodecourse;

    sl = new StudentList();
    sll = new StudentLinkedList();

    auto clock = chrono::high_resolution_clock::now();
    Sleep(100);
    /* Implemented with list*/
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < 2; i++)
    {
        //https://en.cppreference.com/w/cpp/chrono/duration/duration_cast

        auto t2 = std::chrono::high_resolution_clock::now();

        auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - start);

        std::chrono::duration<unsigned int, std::micro> int_usec = int_ms;

        srand(int_usec.count());
        tkn1 = rand() % (90 - 65) + 65;
        tkn2 = rand() % (90 - 65) + 65;
        tkn3 = rand() % (90 - 65) + 65;

        //name = tkn1 + tkn2 + tkn3;
        name.clear();
        name += tkn1;
        name += tkn2;
        name += tkn3;

        student = new Student();
        student->name = name;

        for (int j = 0; j < 2; j++)
        {
            auto t2 = std::chrono::high_resolution_clock::now();

            auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - start);

            std::chrono::duration<unsigned int, std::micro> int_usec = int_ms;

            srand(int_usec.count());
            course = new Course();
           
            tkn1 = rand() % (90 - 65) + 65;
            tkn2 = rand() % (90 - 65) + 65;
            tkn3 = rand() % (90 - 65) + 65;

            //name = tkn1 + tkn2 + tkn3;
            name.clear();
            name += tkn1;
            name += tkn2;
            name += tkn3;

            grade = rand() % 100 + 1;
            credit = rand() % 100 + 1;

            course->credit = credit;
            course->grade = grade;
            course->name = name;

            student->courselist.push_back(*course);
            delete course;

        }
        sl->studentlist.push_back(*student);
        delete student;
    }

    slb.push_back(sl);

    auto finish = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = finish - start;

    cout << "Elapsed time list:" << elapsed.count() << endl;

    /* Implemented with linkedlist*/

    start = chrono::high_resolution_clock::now();

    sll->dllp = new DoublyLinkedList();

    dllc = new DoublyLinkedListCourse();


    for (int i = 0; i < 2; i++)
    {
        
        node = new Node();

        auto t2 = std::chrono::high_resolution_clock::now();

        auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - start);

        std::chrono::duration<unsigned int, std::micro> int_usec = int_ms;

        srand(int_usec.count());

        tkn1 = rand() % (90 - 65) + 65;
        tkn2 = rand() % (90 - 65) + 65;
        tkn3 = rand() % (90 - 65) + 65;

        //name = tkn1 + tkn2 + tkn3;
        name.clear();
        name += tkn1;
        name += tkn2;
        name += tkn3;

        node->name = name;

        sll->dllp->addtail(node);

        for (int j = 0; j < 2; j++)
        {
            nodecourse = new NodeCourse();

            auto t2 = std::chrono::high_resolution_clock::now();

            auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - start);

            std::chrono::duration<unsigned int, std::micro> int_usec = int_ms;

            srand(int_usec.count());

            tkn1 = rand() % (90 - 65) + 65;
            tkn2 = rand() % (90 - 65) + 65;
            tkn3 = rand() % (90 - 65) + 65;

            //name = tkn1 + tkn2 + tkn3;
            name.clear();
            name += tkn1;
            name += tkn2;
            name += tkn3;

            grade = rand() % 100 + 1;
            credit = rand() % 100 + 1;

            nodecourse->credit = credit;
            nodecourse->grade = grade;
            nodecourse->name = name;

            dllc->addtail(nodecourse);
           
        }
        
        node->dllcourse = dllc;
    }

    slb.push_back(sll);

    finish = chrono::high_resolution_clock::now();

    elapsed = finish - start;

    cout << "Elapsed time linked list:" << elapsed.count() << endl;

    cout << "List" << endl;
    slb[0]->print();
    cout << "Linked list" << endl;
    slb[1]->print();

    delete sl;
    delete sll;

}

void StudentList::print()
{
    list<Student>::iterator it;

    for (it = studentlist.begin(); it != studentlist.end(); ++it)
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

void StudentLinkedList::print()
{
    dllp->display_forward();
   
}

StudentLinkedList::StudentLinkedList()
{
    dllp = new DoublyLinkedList();
}

StudentLinkedList::~StudentLinkedList()
{
    delete dllp;
}

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

    //cout << "Data : " << data->data << endl;

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
    //delete dllcourse;

    //dllcourse->~DoublyLinkedListCourse();
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