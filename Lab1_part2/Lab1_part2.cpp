// Lab1_part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Lab1_part2.h"

int main()
{
	/*
	stack<char> stackone;
	stack<char> stacktwo;
	queue<char> queueone;
	queue<char> queuetwo;
	
	string palindrome;


	cout << "Enter palindrome:";
	cin >> palindrome;
	*/

	palindrometester pt;

	pt.testpalindrome();

	/*
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
	*/
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

void palindrometester::testpalindrome()
{
	string st;
	bool isPalindrome = false;
	int numofchars = 1;
	//cout << "Enter string to test :";

	//cin >> st;

	for (int i = 1; i <= 4; i++)
	{
		scs1.clear();
		scs2.clear();
		qcs1.clear();
		qcs2.clear();

		numofchars *= 10;
		generatestring(st, numofchars);

		removechars(st);

		// https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case

		std::transform(st.begin(), st.end(), st.begin(),
			[](unsigned char c) { return std::tolower(c); });

		// Load stacks
		for (int i = 0; i < (st.length() / 2); i++)
		{
			scs1.push(st[i]);
			scs2.push(st[st.length() - i - 1]);
		}

		// Load queues
		for (int j = 0; j < (st.length() / 2); j++)
		{
			qcs1.enqueue(st[j]);
			qcs2.enqueue(st[st.length() - 1 - j]);
		}

		auto start = chrono::high_resolution_clock::now();

		if (teststacks() == true)
			cout << "Stack IS palindrome" << endl;
		else
			cout << "Stack is NOT palindrome" << endl;

		auto t2 = std::chrono::high_resolution_clock::now();

		auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - start);

		std::chrono::duration<unsigned int, std::micro> int_usec = int_ms;

		cout << "Stack " << numofchars << " characters took : " << int_usec.count() << endl;

		start = chrono::high_resolution_clock::now();

		if (testqueues() == true)
			cout << "Queue IS palindrome" << endl;
		else
			cout << "Queue is NOT palindrome" << endl;

		t2 = std::chrono::high_resolution_clock::now();

		int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - start);

		int_usec = int_ms;

		cout << "Queue " << numofchars << " characters took : " << int_usec.count() << endl;

		
	}
}

void palindrometester::generatestring(string& st, int numberofchars)
{
	char tkn;
	st.clear();
	auto start = chrono::high_resolution_clock::now();

	for (int i = 1; i < numberofchars; i++)
	{
		auto t2 = std::chrono::high_resolution_clock::now();

		auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - start);

		std::chrono::duration<unsigned int, std::micro> int_usec = int_ms;

		srand(int_usec.count());
		tkn = rand() % (90 - 65) + 65;

		//st += tkn;
		st += 'A';
	}
}

void palindrometester::removechars(string& stringtoremove)
{
	string temp;

	temp.clear();

	for (int i = 0; i < stringtoremove.length(); i++)
	{
		if (stringtoremove[i] == ' ' || stringtoremove[i] == '.')
		{

		}
		else
		{
			temp += stringtoremove[i];
		}
	}

	stringtoremove.clear();
	stringtoremove = temp;
}

bool palindrometester::teststacks()
{
	// Test stacks

	while (scs1.isEmpty() == false && scs2.isEmpty() == false)
	{
		if (scs1.peek() != scs2.peek())
			return false;

		scs1.pop();
		scs2.pop();
	}
	return true;
}

bool palindrometester::testqueues()
{
	while (qcs1.isEmpty() == false && qcs2.isEmpty() == false)
	{
		if (qcs1.peek() != qcs2.peek())
			return false;

		qcs1.dequeue();
		qcs2.dequeue();
	}

}


void queuecstyle::clear()
{
	front = 0;
	rear = -1;
	count = 0;
}

queuecstyle::queuecstyle(int size)
{
	arr = new char[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

queuecstyle::~queuecstyle()
{
 	delete[] arr;
}

void queuecstyle::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue underflow" << endl;
	}
	else
	{
		//cout << "Removeing " << arr[front] << endl;

		for (int i = 1; i < count; i++)
		{
			arr[i - 1] = arr[i];
		}
		count--;
	}
}

void queuecstyle::enqueue(char item)
{
	if (isFull())
	{
		cout << "Queue overflow" << endl;
	}
	else
	{
		//cout << "Inserting " << item << endl;

		//rear = (rear + 1) % capacity;
		//arr[rear] = item;
		
		arr[count] = item;
		count++;
	}
}

char queuecstyle::peek()
{
	if (isEmpty())
	{
		cout << "Underflow" << endl;
	}
	else
	{
		return arr[front];
	}
}

int queuecstyle::size()
{
	return count;
}

bool queuecstyle::isEmpty()
{
	return (size() == 0);
}

bool queuecstyle::isFull()
{
	return (size() == capacity);
}

void stackcstyle::clear()
{
	top = -1;
}

stackcstyle::stackcstyle(int size)
{
	arr = new char[size];
	capacity = size;
	top = -1;
}

stackcstyle::~stackcstyle()
{
	delete[] arr;
} 

void stackcstyle::push(char x)
{
	if (isFull())
	{
		cout << "Stack overflow" << endl;
	}
	else
	{
		//cout << "Inserting " << x << endl;
		arr[++top] = x;
	}
}

char stackcstyle::pop()
{
	if (isEmpty())
	{
		cout << "Stack underflow" << endl;
	}
	else
	{
		//cout << "Remove " << peek() << endl;
		return arr[top--];
	}
}

char stackcstyle::peek()
{
	if (!isEmpty())
	{
		return arr[top];
	}
	else
		return 0;
}

int stackcstyle::size()
{
	return top + 1;
}

bool stackcstyle::isEmpty()
{
	return top == -1;
}

bool stackcstyle::isFull()
{
	return top == capacity - 1;
}