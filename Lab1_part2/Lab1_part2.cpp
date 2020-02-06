// Lab1_part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>
#include <chrono>

using namespace std;
bool is_palindrome_with_stack(stack<char>& sto, stack<char>& stt);
bool is_palindrome_with_queue(queue<char>& quo, queue<char>& qut);

int main()
{
	stack<char> stackone;
	stack<char> stacktwo;
	queue<char> queueone;
	queue<char> queuetwo;
	string palindrome;

	cout << "Enter palindrome:";
	cin >> palindrome;

	stackone.empty();
	stacktwo.empty();
	queueone.empty();
	queuetwo.empty();

// Load stacks

	for (int i = 0; i < palindrome.length(); i++)
	{
		stackone.push(palindrome[i]);
		stacktwo.push(palindrome[palindrome.length() - 1 - i]);
	}

// Load queues

	for (int j = 0; j < palindrome.length(); j++)
	{
		queueone.push(palindrome[j]);
		queuetwo.push(palindrome[palindrome.length() - 1 - j]);
	}

	auto start = chrono::high_resolution_clock::now();

	if (is_palindrome_with_stack(stackone, stacktwo))
	{
		cout << "Stack IS palindrome" << endl;
	}
	else
	{
		cout << "Stack is NOT palindrome" << endl;
	}
	
	auto finish = chrono::high_resolution_clock::now();
	
	chrono::duration<double> elapsed = finish - start;

	cout << "Stack elapsed time :" << elapsed.count() << endl;
	
	start = chrono::high_resolution_clock::now();

	if (is_palindrome_with_queue(queueone, queuetwo))
	{
		cout << "Queue IS palindrome" << endl;
	}
	else
	{
		cout << "Queue is NOT palindrome" << endl;
	}

	finish = chrono::high_resolution_clock::now();

	elapsed = finish - start;

	cout << "Queue elapsed time :" << elapsed.count() << endl;
}

bool is_palindrome_with_stack(stack<char>& sto, stack<char>& stt)
{
	bool ispalindrome = true;

	while (sto.empty() == false && stt.empty() == false)
	{
		if (sto.top() != stt.top())
			return false;
		sto.pop();
		stt.pop();
	}

	return true;
}

bool is_palindrome_with_queue(queue<char>& quo, queue<char>& qut)
{
	while (quo.empty() == false && qut.empty() == false)
	{
		if (quo.front() != qut.front())
			return false;
		quo.pop();
		qut.pop();
	}

	return true;
}

bool is_palindrome(char testword[], int ll) {
	const int l = 10;
	//const int l = ll;
	char reverse[l] = { "xxxxxxxxx" };
	bool palindrome = true;

	for (int i = 0; i < l; i++)
	{
		reverse[i] = testword[l - 1 - i];
	}

	for (int j = 0; j < l; j++)
	{
		if (reverse[j] != testword[j])
		{
			palindrome = false;
		}
	}
	return palindrome;
}