#include <string>
#include <iostream>
#include<cctype>
using namespace std;
string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}
void PrintFirstLetterOfEachWord(string S1)
{
	bool isFirstLetter = true;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = toupper(S1[i]);
		}
		isFirstLetter = (S1[i] == ' ' ? true : false);
	}
	cout << endl << S1 << endl;
}
int main()
{
	PrintFirstLetterOfEachWord(ReadString());
	system("pause>0");
}