#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;
string FunReadTheString()
{
	string MyString = "Test";

	getline(cin, MyString);

	return MyString;
}
bool FunIsPunct(char MyChar)
{
	return ispunct(MyChar);
}
string FunRemoveThePunctuations(string &MyString)
{

	string result = "";

	for (int i = 0; i < MyString.length(); i++)
	{
		if (!FunIsPunct(MyString[i]))
		{
			result += MyString[i];
		}
	}

	return result;
}
int main()
{

	string MyString = "Test";

	cout << "enter your string : ";

	MyString = FunReadTheString();

	cout << "\n\nyour string befor remove the punctuation : "<< MyString;

	cout << "\n\nyour string after remove the punctuation : " << FunRemoveThePunctuations(MyString);
	

	return 0;
}
