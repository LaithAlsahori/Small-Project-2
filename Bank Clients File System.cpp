#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
const string FileName = "ClientData.txt";
struct StrThe_Data
{
	string AccountNumber = "test";
	string PinNumber = "test";
	string Name = "test";
	string Phone = "test";
	float AccountBalance = 0.0;
};
StrThe_Data FunRead_The_Data(StrThe_Data &The_Data)
{
	cout << "enter the account number : ";
	cin >> The_Data.AccountNumber;

	cout << "enter the pin number : ";
	cin >> The_Data.PinNumber;

	cin.ignore();
	cout << "enter client name : ";
	getline(cin, The_Data.Name);

	cout << "enter client phone number : ";
	cin >> The_Data.Phone;

	cout << "enter the account balance : ";
	cin >> The_Data.AccountBalance;

	return The_Data;
}
string FunConvert_The_Data_To_Line(StrThe_Data The_Data,string limiter)
{
	string Line = "";

	Line += The_Data.AccountNumber + limiter;
	Line += The_Data.PinNumber + limiter;
	Line += The_Data.Name + limiter;
	Line += The_Data.Phone + limiter;
	Line += to_string(The_Data.AccountBalance);

	return Line;
}
void FunSave_The_Line_In_File(StrThe_Data& The_Data)
{
	fstream ClientFile;

	ClientFile.open(FileName, ios::app | ios::out);

	if (ClientFile.is_open())
	{
		ClientFile << FunConvert_The_Data_To_Line(FunRead_The_Data(The_Data), "#//#");
		cout << endl;
	}

	ClientFile.close();
}
vector <string> FunReturn_The_Data_From_File(vector<string> &vData)
{
	StrThe_Data The_Data;
	fstream ClientFile;

	ClientFile.open(FileName, ios::in);

	string Line = "test";

	while (getline(ClientFile, Line))
	{
		vData.push_back(Line);
	}

	return vData;
}
string FunRead_The_Account_Number()
{
	string AccountNum = "test";

	cin >> AccountNum;

	return AccountNum;
}
bool FunIf_User_Exist(vector<string> &vData,string limiter)
{
	string AccNumUser = FunRead_The_Account_Number();

	for (int i = 0; i < vData.size(); i++)
	{
		int pos = vData[i].find(limiter);

		string AccNum = vData[i].substr(0, pos);

		if (AccNum == AccNumUser)
		{
			return true;
		}
	}

	return false;

}
void FunIs_User_Exist(vector<string> &vData)
{
	if (FunIf_User_Exist(vData,"#//#"))
	{
		cout << "\n\nthe user is exist ";
    }
	else
	{
		cout << "\n\nthe user is not exist ";
	}

}
void FunReset_File()
{
	fstream File;
	File.open("ClientData.txt", ios::out); 

	File.close();
}
int main()
{
	StrThe_Data The_Data;
	vector<string> vData;

	FunReset_File();

	FunSave_The_Line_In_File(The_Data);

	FunReturn_The_Data_From_File(vData);

	cout << "\n\nenter the account number of user you want fint it : ";
	FunIs_User_Exist(vData);

	return 0;
}