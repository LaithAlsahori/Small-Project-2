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
int FunCount_Number_Of_Letter(string test)
{
	return test.length();
}
int FunCount_Number_Of_Big_Letter(string test)
{
	int count = 0;

	for (int i = 0; i < test.length(); i++)
	{
		isupper(test[i]) ? count++ : false;

	}
	return count;
}
int FunCount_Number_Of_Small_Letter(string test)
{
	int count = 0;

	for (int i = 0; i < test.length(); i++)
	{
		islower(test[i]) ? count++ : false;

	}
	return count;
}
int main()
{
	cout << "enter your full name : ";
	string name = FunRead_The_Name();

	cout << "the number of letter is : " << FunCount_Number_Of_Letter(name);
	cout << "\nthe number of big letter is : " << FunCount_Number_Of_Big_Letter(name);
	cout << "\nthe number of small letter is : " << FunCount_Number_Of_Small_Letter(name);

	cout << endl;
	return 0;
}
