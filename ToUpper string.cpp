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
void FunConvert_The_Name_ToUpper_Letter()
{
	string test = FunRead_The_Name();

	cout << "your name after : ";

	for (int i = 0; i < test.length(); i++)
	{
		if (test[i] != ' ')
		{
			test[i] = toupper(test[i]);
			cout << test[i];
		}
		else
		{
			cout << " ";
		}
	}
}
int main()
{
	string S1 = "laith";

	cout << "enter your fill name : ";
	FunConvert_The_Name_ToUperr_Letter();
	return 0;
}
