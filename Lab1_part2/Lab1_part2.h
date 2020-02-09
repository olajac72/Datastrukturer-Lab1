#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <chrono>

#include <algorithm>
#include <cctype>
#include <string>

using namespace std;
bool is_palindrome_with_stack(stack<char>& sto, stack<char>& stt);
bool is_palindrome_with_queue(queue<char>& quo, queue<char>& qut);

// https://www.techiedelight.com/queue-implementation-cpp/

#define QUEUESIZE 100;

class queuecstyle
{
private:
	char* arr;
	int capacity;
	int front;
	int rear;
	int count;

public:
	queuecstyle(int size = 100);
	~queuecstyle();

	void dequeue();
	void enqueue(char x);
	char peek();
	int size();
	bool isEmpty();
	bool isFull();
	void clear();
};

// https://www.techiedelight.com/stack-implementation-in-cpp/

class stackcstyle
{
private:
	char* arr;
	int top;
	int capacity;
public:
	stackcstyle(int size = 100);
	~stackcstyle();

	void push(char);
	char pop();
	char peek();
	int size();
	bool isEmpty();
	bool isFull();
	void clear();
};

class palindrometester
{
public:
	stackcstyle scs1, scs2;
	queuecstyle qcs1, qcs2;
	void testpalindrome();
	bool teststacks();
	bool testqueues();
	void removechars(string& stringtoremove);
};