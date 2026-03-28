#include<iostream>
#include<string>
#include<vector>
using namespace std;
string FunRead_The_String()
{
	string MyString = "Test";

	getline(cin, MyString);

	return MyString;
}
vector <string> FunFill_The_String_In_vector(string MyString)
{
	vector <string> vString;
	short pos = 0;
	string space = " ";

	while ((pos = MyString.find(space)) != std::string::npos)
	{
		vString.push_back(MyString.substr(0, pos));

		MyString.erase(0, pos + space.length());
	}
	if (MyString != " ")
	{
		vString.push_back(MyString);
	}

	return vString;
}
void FunChange_The_Position_Words(vector <string> &vString,string word1, string word2)
{
	vector <string>::iterator iter1= vString.end();
	vector <string>::iterator iter2 = vString.end();

	for (vector <string>::iterator iter = vString.begin(); iter != vString.end(); iter++)
	{
		if (*iter == word1)
		{
			iter1 = iter;
		}
		if (*iter == word2)
		{
			iter2 = iter;
		}
	}
	if (iter1 != vString.end() && iter2 != vString.end())
	{
		swap(*iter1, *iter2);
	}
}
void FunPrint_The_Vector(vector <string>& vString)
{
	for (string test : vString)
	{
		cout << test+" ";
	}
}
int main()
{
	vector<string> vTest;

	cout << "enter your string : ";
	vTest=FunFill_The_String_In_vector(FunRead_The_String());

	FunChange_The_Position_Words(vTest, "laith", "ali");

	FunPrint_The_Vector(vTest);

	return 0;
}