// Palindromechecker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool is_palindrome(char testword[], int ll) {
	const int l = 10;
	//const int l = ll;
	char reverse[l] = { "xxxxxxxxx" };
	bool palindrome = true;

	for (int i = 0; i < l; i++)
	{
		reverse[i] = testword[l - 1 - i];
	}

	for (int j = 0; j < l ; j++)
	{
		if (reverse[j] != testword[j])
		{
			palindrome = false;
		}
	}
	return palindrome;
}

int main()
{
	const int l = 10;
	char wordtest[l] = {"xxxxxxxxx"};
	printf("Enter %i characters :", l);
	int res = scanf("%s",wordtest);

	cout << "Word is " << wordtest << endl;

 	if (is_palindrome(wordtest, l) == true)
	{
		cout << "Word is a palindrome" << endl;
	}
	else
	{
		cout << "Word is NOT a palindrome" << endl;
	}
}
 