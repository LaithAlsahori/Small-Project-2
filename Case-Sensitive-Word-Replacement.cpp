#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
string FunReadTheString()
{
	string MyString = "Test";

	getline(cin, MyString);

	return MyString;
}
vector <string> FunFillTheVectorUsingString(string MyString)
{
	vector <string> vSting;
	short pos = 0;
	string s = "test";
	string limiter = " ";

	while ((pos=MyString.find(limiter))!=std::string::npos)
	{
		vSting.push_back(MyString.substr(0, pos));

		MyString.erase(0, pos + limiter.length());
	}

	if (MyString != " ")
	{
		vSting.push_back(MyString);
	}

	return vSting;
}
string FunReturnToLowerLetter(string MyString)
{
	for (int i = 0; i < MyString.length(); i++)
	{
		MyString[i] = tolower(MyString[i]);
    }

	return MyString;
}
vector <string> FunReplaceTheWordsInVector(vector <string> &vString,string beforWord,string aftereWord
,bool Case=true )
{
	for (string& test : vString) 
	{
		if (Case)
		{
			if (test == beforWord)
			{
				test = aftereWord;
			}
		}
		else
		{
	
			if (FunReturnToLowerLetter(test) == FunReturnToLowerLetter(beforWord))
			{
				test = aftereWord;
			}
		}
	}
	return vString;
}
int main()
{
	vector<string> vtest;

	cout << "enter your string : ";
	vtest=FunFillTheVectorUsingString(FunReadTheString());

	cout << "\n\nyour string is : ";

	for (string test : vtest)
	{
		cout << test << " ";
	}

	cout << "\n\nyour string using case sensitive : ";
	FunReplaceTheWordsInVector(vtest, "jordan", "usa",1);


	for (string test : vtest)
	{
		cout << test<<" ";
	}

	cout << "\n\nyour string without case sensitive : ";
	FunReplaceTheWordsInVector(vtest, "jordan", "usa", 0);

	for (string test : vtest)
	{
		cout << test << " ";
	}
	return 0;
}
