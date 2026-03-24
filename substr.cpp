#include<iostream>
#include<string>
using namespace std;
string FunRead_The_String()
{
	string MyString;

	cout << "enter your string : ";

	getline(cin, MyString);

	return MyString;
}
void FunPrint_Your_String(string MyString)
{
	cout << "your string words are : \n";
	cout << endl;

	short pos = 0;
	string s = "laith";
	string space = " ";

	while ((pos = MyString.find(space))!=std::string::npos)
	{
		
		s = MyString.substr(0, pos);

		cout << s << endl;

		MyString.erase(0, pos + space.length());
	}
	if (MyString != "")
	{
		cout << MyString << endl;
	}
}
int main()
{
	FunPrint_Your_String(FunRead_The_String());

	return 0;
}