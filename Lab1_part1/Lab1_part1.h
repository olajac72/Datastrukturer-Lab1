#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <time.h>
#include <chrono>
#include <windows.h>

using namespace std;

class Node;
class NodeCourse;
class Course;
class Student;
class DoublyLinkedList;
class StudentListBase;
class StudentList;
class StudentLinkedList;

class StudentListTest
{
private:
	vector<StudentListBase*> slb;
	StudentList* sl;
	StudentLinkedList* sll;

public:
	void generateTest();
};

class StudentListBase
{
public:
	virtual void print() = 0;
};

class StudentList : public StudentListBase
{
public:
	list<Student> studentlist;
	void print();
};

class StudentLinkedList : public StudentListBase
{
public:
	StudentLinkedList();
	~StudentLinkedList();
	DoublyLinkedList* dllp;
	void print();
};

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

class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
	int numberofnodes;

public:
	
	DoublyLinkedList();
	~DoublyLinkedList();
	bool remove(int pos);
	bool add(Node* data, int pos);
	bool replace(Node* oldnode, Node* newnode);
	bool addtail(Node* data);
	//bool remove(int pos);
	//bool replace(Node* oldnode, Node* newnode);
	//int search(Node* data);
	//Node* nodeAt(int pos);
	void display_forward();
	void display_backward();
	//void display_backward();
	//int size();
};

class DoublyLinkedListCourse
{
private:
	NodeCourse* head;
	NodeCourse* tail;
	int numberofnodes;

public:
	DoublyLinkedListCourse();
	~DoublyLinkedListCourse();
	bool remove(int pos);
	bool add(NodeCourse* data, int pos);
	bool replace(NodeCourse* oldnode, NodeCourse* newnode);
	bool addtail(NodeCourse* data);
	//bool remove(int pos);
	//bool replace(Node* oldnode, Node* newnode);
	//int search(Node* data);
	//Node* nodeAt(int pos);
	void display_forward();
	void display_backward();
	//void display_backward();
	//int size();
};

class Node
{
private:

public:
	int data;
	int nodeNumber;
	string name;
	DoublyLinkedListCourse* dllcourse;

	Node* next;
	Node* prev;
	Node();
	~Node();
	//int getData();
	//void setData(int data);
	//Node* getNext();
	//void setNext(Node* next);
	//Node* getPrev();
	//void setPrev(Node* prev);
};

class NodeCourse
{
private:

public:
	string name;
	float credit;
	int grade;

	int data;
	int nodeNumber;
	NodeCourse* next;
	NodeCourse* prev;
	NodeCourse();
	//int getData();
	//void setData(int data);
	//Node* getNext();
	//void setNext(Node* next);
	//Node* getPrev();
	//void setPrev(Node* prev);
};