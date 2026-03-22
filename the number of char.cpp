#include<iostream>
#include<string>
#include<cctype>
#include <limits>
using namespace std;
string FunRead_The_Name()
{
	string test = "laith";

	getline(cin, test);

	return test;

}
char FunRead_The_char()
{
	char charTest = 'a';

	do
	{
		cout << "enter the character: ";
		cin >> charTest;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "enter the character: ";
			cin >> charTest;
		}

		return charTest; // مهم جداً
	} while (true);
}
int FunThe_Number_Of_Your_char(string MyName, char MyChar)
{
	int count = 0;

	for (int i = 0; i < MyName.length(); i++)
	{
		if (MyName[i] == MyChar)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	cout << "enter your full name : ";
	string testName = FunRead_The_Name();

	
	char testChar = FunRead_The_char();

	cout << "\n\nthe number of your character " << testChar << " is : " << FunThe_Number_Of_Your_char(testName, testChar);


		cout << endl;
	return 0;
}
