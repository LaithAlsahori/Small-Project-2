#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
struct StrThe_Data
{
	string AccountNumber = "aaa";
	short PinCode = 0;
	string Name = "aaa";
	short PhoneNumber = 0;
	float AccountBalance = 0.0;
};
StrThe_Data FunRead_The_Data(StrThe_Data &The_Data)
{
	cout << "\nenter your account number : ";
	cin >> The_Data.AccountNumber;

	cout << "enter your Pin code : ";
	cin >> The_Data.PinCode;

	cin.ignore();

	cout << "enter your name : ";
	getline(cin, The_Data.Name);

	cout << "enter your phone number : ";
	cin >> The_Data.PhoneNumber;

	cout << "enter your account balance : ";
	cin >> The_Data.AccountBalance;

	return The_Data;
}
string FunConvert_To_One_Line(StrThe_Data The_Data,string limiter)
{

	string MyString = "";

	MyString += The_Data.AccountNumber + limiter;
	MyString += to_string(The_Data.PinCode)+limiter;
	MyString += The_Data.Name + limiter;
	MyString += to_string(The_Data.PhoneNumber) + limiter;
	MyString += to_string(The_Data.AccountBalance) + limiter;

	return MyString;

}
vector <string> FunAdd_Euch_Clients_To_Vector(StrThe_Data& The_Data)
{
	string TheClient = "Test";
	vector <string> vClientData;
	char choice = 'Y';

	do
	{

		TheClient = FunConvert_To_One_Line(FunRead_The_Data(The_Data), "#//#");
		vClientData.push_back(TheClient);

		cout << "\n\nenter y | Y if you want enter a new client : ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');

	return vClientData;
}
void FunSave_The_Data_In_File(vector <string>& vClientData, StrThe_Data& The_Data)
{
	fstream FileOfDataClient;
	string LineOfData = "test";
	
	FileOfDataClient.open("FileOfDataClient.txt",  ios::app |  ios::out);

	if (FileOfDataClient.is_open())
	{

		for (string line : vClientData)
		{
			FileOfDataClient << line << endl;
		}

		FileOfDataClient.close();
	}

}
vector <string> FunRemove_Limiter(string TheDataLine,string limiter)
{
	vector <string> vString;
	short pos = 0;

	while ((pos=TheDataLine.find(limiter))!=std::string::npos)
	{
		vString.push_back(TheDataLine.substr(0, pos));
		TheDataLine.erase(0,pos+limiter.length());
	}
	if (!TheDataLine.empty())
	{
		vString.push_back(TheDataLine);
	}

	return vString;
}
vector<string>  FunLoad_Data_From_File_To_Vector(vector<string> &vLodeData)
{
	fstream FileOfDataClient;

	FileOfDataClient.open("FileOfDataClient.txt", ios::in);
	
	if (FileOfDataClient.is_open())
	{
		string line;

		while (getline(FileOfDataClient, line))
		{
			vector<string> parts = FunRemove_Limiter(line, "#//#");
			for (string s : parts)
				vLodeData.push_back(s);
		}
		FileOfDataClient.close();
	}
	return vLodeData;
}
void FunPrint_The_Table(vector<string>& vLodeData)
{
	cout <<"--------------------------------------------------------------------\n";
	cout << "| Account number | pin number |client name       | phone | balance |";
	cout << "\n--------------------------------------------------------------------\n";
	for (size_t i = 0; i < vLodeData.size(); i++)
	{
		cout << setw(16) << vLodeData[i] << " |";

		
		if ((i + 1) % 5 == 0)
			cout << endl;
	}
	cout << "-------------------------------------------------------------\n";
}
int main()
{
	StrThe_Data The_Data;
	vector<string> vLodeData;

	vector<string> vClientData = FunAdd_Euch_Clients_To_Vector(The_Data);


	FunSave_The_Data_In_File(vClientData,The_Data);

	FunLoad_Data_From_File_To_Vector(vLodeData);
	 FunPrint_The_Table(vLodeData);
	


	return 0;
}