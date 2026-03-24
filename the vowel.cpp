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
void FunThe_Vowel(string word)
{
	cout << "your vowel letter in your string : ";

	for (int i = 0; i < word.length(); i++)
	{
		if (FunThe_Char_Is_Vowel(word[i]))
		{
			cout << word[i] << " ";
	    }
	}
	
}
int main()
{

	cout << "enter your word : ";
	string MyString = FunRead_The_Name();

	FunThe_Vowel(MyString);

	return 0;
}
