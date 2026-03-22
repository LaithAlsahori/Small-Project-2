#include<iostream>
#include<string>
using namespace std;
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
bool FunThe_Char_Is_Vowel(int MyChar)
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
int main()
{

	char testChar = FunRead_The_char();

	if (FunThe_Char_Is_Vowel(testChar))
	{
		cout << "your character is vowel\n";
	}
	else
	{
		cout << "your character is not vowel\n";
	}

	return 0;
}