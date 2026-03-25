#include<iostream>
#include<string>
#include<vector>
using namespace std;
string FunRead_The_string()
{
	string MyString = "laith";

		cout << "enter your string \n";

	getline(cin, MyString);

	return MyString;
}
string FunTrim_To_Left(string MyString)
{

	while (!MyString.empty() && MyString.front() == ' ')
	{
		MyString.erase(0, 1);
	}

	cout<<endl << MyString;

	return MyString;
}
string FunTrim_To_Right(string MyString)
{

	while (!MyString.empty() && MyString.back() == ' ')
	{
		MyString.pop_back();
	}

	cout << endl << MyString;

	return MyString;
}
int main()
{
	FunTrim_To_Left(FunRead_The_string());
	FunTrim_To_Right(FunRead_The_string());

	return 0;
}