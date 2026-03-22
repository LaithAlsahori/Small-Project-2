#include<iostream>
#include<string>
#include<cctype>
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

		return charTest;
	} while (true);
}
bool FunThe_Char_Is_Vowel(char MyChar)
{
	switch (MyChar)
	{
	case 'a':
		return true;
		break;

	case 'o':
		return true;
		break;

	case 'i':
		return true;
		break;

	case 'u':
		return true;
		break;

	case 'e':
		return true;
		break;

	default:
		return false;

	}
}
int FunThe_Number_Of_Vowel(string word)
{
	int counter = 0;

	for (int i = 0; i < word.length(); i++)
	{
		if (FunThe_Char_Is_Vowel(word[i]))
		{
			counter++;
		}
	}
	return counter;
}
int main()
{

	cout << "enter your word : ";
	string MyString=FunRead_The_Name();

	cout << "the number of vowel in your word is : "<<FunThe_Number_Of_Vowel(MyString);
	cout << endl;

	return 0;
}
