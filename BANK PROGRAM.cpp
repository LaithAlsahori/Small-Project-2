#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include <limits>

using namespace std;

struct StrTheData
{
	string AccountNumber;
	string PinNumber;
	string NameClient;
	string PhoneNumber;
	string BalanceNumber;
};

enum EnTheChoice {
	ShowClientList = 1, AddNewClient = 2, DeleteClient = 3,
	UpdateClientInfo = 4, FindClient = 5, RemoveAllClient = 6, Transaction = 7
	, Exit = 8
};

enum EnTheTransactionChoice { Deposit = 1, Withdraw = 2, TotalBalance = 3, MainMenu = 4 };

string FunReadTheAccountNumber()
{
	string AccountNumber = "";

	cout << "ENTER THE ACCOUTN NUMBER : ";
	cin >> AccountNumber;

	return AccountNumber;
}

void FunDeleteTheMainMenu();

void FunStart(vector <StrTheData>& vStrTheData);
void FunStartTheTransaction(vector <StrTheData>& vStrTheData);

//قسم تحويل البيانات على خط و حفظها في الملف //

StrTheData ReadTheData()
{
	StrTheData TheData;

	cout << "---[ ENTER THE DATA ]---\n";

	cout << "ENTER THE ACCOUNT NUMBER : ";
	cin >> TheData.AccountNumber;

	cout << "ENTER THE PIN NUMBER : ";
	cin >> TheData.PinNumber;

	cin.ignore();

	cout << "ENTER THE CLIENT NAME : ";
	getline(cin, TheData.NameClient);

	cout << "ENTER THE PHONE NUMBER OF CLIENT : ";
	cin >> TheData.PhoneNumber;

	cout << "ENETR THE ACCOUNT BALANCE : ";
	cin >> TheData.BalanceNumber;

	return TheData;
}

string FunConvertTheStructToLine(StrTheData TheData, string Limiter)
{
	string Line = "";

	Line += TheData.AccountNumber + Limiter;
	Line += TheData.PinNumber + Limiter;
	Line += TheData.NameClient + Limiter;
	Line += TheData.PhoneNumber + Limiter;
	Line += TheData.BalanceNumber;

	return Line;
}

void FunSaveTheLineInFile(string Line)
{
	fstream ClientDataFile;

	string LocationFile = "MyFile.txt";

	ClientDataFile.open(LocationFile, ios::out | ios::app);

	ClientDataFile << Line << endl;

	ClientDataFile.close();
}

//حفظ المستخدمين من الملف الى vector ثم الى struct ثم الى vector //

vector <string> FunSplitTheLine(string Line, string Limiter)
{
	vector <string> vString;

	short Pos = 0;
	string Container = "";

	while ((Pos = Line.find(Limiter)) != std::string::npos)
	{
		Container = Line.substr(0, Pos);

		if (Container != " ")
		{
			vString.push_back(Container);
		}
		Line.erase(0, Pos + Limiter.length());
	}
	if (!(Line.empty()))
	{
		vString.push_back(Line);
	}
	return vString;

}

StrTheData FunConvertTheVectorToStruct(vector <string> vString)
{
	StrTheData StrTheData;

	StrTheData.AccountNumber = vString[0];
	StrTheData.PinNumber = vString[1];
	StrTheData.NameClient = vString[2];
	StrTheData.PhoneNumber = vString[3];
	StrTheData.BalanceNumber = vString[4];

	return StrTheData;
}

vector<StrTheData> FunReadTheLineFromFile()
{
	StrTheData TheData;
	vector <string> vString;
	vector <StrTheData> vStrTheData;

	fstream ClientDataFile;

	string LocationFile = "MyFile.txt";

	ClientDataFile.open(LocationFile, ios::in);

	string Line;

	while (getline(ClientDataFile, Line))
	{
		vString = FunSplitTheLine(Line, "#//#");

		TheData = FunConvertTheVectorToStruct(vString);

		vStrTheData.push_back(TheData);
	}
	ClientDataFile.close();

	return vStrTheData;
}

//Show Client List//

void FunPrintTheHeaderOfClient()
{
	cout << "--------------------------------------------------------------------------\n";
	cout << "| AccountNumber | PinNumber | ClientName | PhoneNumber | BalanceNumber   |\n";
	cout << "--------------------------------------------------------------------------\n";
}

void FunPrintTheBodyOfClient(vector <StrTheData> vStrTheData)
{
	for (StrTheData& TheData : vStrTheData)
	{
		cout << "|" << setw(13) << TheData.AccountNumber;
		cout << "|" << setw(13) << TheData.PinNumber;
		cout << "|" << setw(13) << TheData.NameClient;
		cout << "|" << setw(13) << TheData.PhoneNumber;
		cout << "|" << setw(13) << TheData.BalanceNumber;
		cout << "   |" << endl;
	}
	if (vStrTheData.empty())
	{
		cout << "NO USERS ADD A NEW USER AND TRY AGAIN\n";
	}
	cout << "--------------------------------------------------------------------------\n";
}

//Delete Client//

vector<StrTheData> FunDeleteTheUser(vector<StrTheData> vStrTheData, string AccountNumber)
{
	bool found = false;
	for (int i = 0; i < vStrTheData.size(); i++)
	{
		if (vStrTheData[i].AccountNumber == AccountNumber)
		{
			vStrTheData.erase(vStrTheData.begin() + i);
			cout << "USER DELETED SUCCESSFULLY\n";
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "CLIENT NOT FOUND\n";
	}


	fstream ClientDataFile;
	ClientDataFile.open("MyFile.txt", ios::out);

	for (StrTheData& Client : vStrTheData)
	{
		ClientDataFile << FunConvertTheStructToLine(Client, "#//#") << endl;
	}

	ClientDataFile.close();

	return vStrTheData;
}

//Update Client Info//

vector<StrTheData> FunUpdateTheData(vector<StrTheData> vStrTheData, string AccountNumber)
{
	for (int i = 0; i < vStrTheData.size(); i++)
	{
		if (vStrTheData[i].AccountNumber == AccountNumber)
		{
			StrTheData temp = ReadTheData();
			temp.AccountNumber = vStrTheData[i].AccountNumber;
			vStrTheData[i] = temp;
			cout << "USER UPDATE SUCCESSFULLY\n";
			break;
		}
	}

	fstream ClientDataFile;
	ClientDataFile.open("MyFile.txt", ios::out);

	for (StrTheData& Client : vStrTheData)
	{
		ClientDataFile << FunConvertTheStructToLine(Client, "#//#") << endl;
	}

	ClientDataFile.close();

	return vStrTheData;
}

// Find Client //

void FunPrintTheDataClientCard(vector<StrTheData> vStrTheData, string AccountNumber)
{
	bool found = false;

	for (int i = 0; i < vStrTheData.size(); i++)
	{
		if (vStrTheData[i].AccountNumber == AccountNumber)
		{
			cout << "-------------------------------\n";
			cout << "THE ACCOUNT NUMBER : " << vStrTheData[i].AccountNumber << endl;
			cout << "THE PIN NUMBER : " << vStrTheData[i].PinNumber << endl;
			cout << "THE NAME CLIENT : " << vStrTheData[i].NameClient << endl;
			cout << "THE PHONE NUMBER : " << vStrTheData[i].PhoneNumber << endl;
			cout << "THE BALANCE NUMBER :" << vStrTheData[i].BalanceNumber << endl;
			cout << "-------------------------------\n";
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "CLIENT NOT FOUND\n";
	}
}

//Transaction//

void FunEditTheDeposit(vector<StrTheData>& vStrTheData, string AccountNumber)
{
	int deposit = 0;
	int test = 0;
	bool found = false;

	cout << "=====================================\n";
	cout << "=           DEPOSIT SCREEN            =\n";
	cout << "=====================================\n";

	for (int i = 0; i < vStrTheData.size(); i++)
	{
		if (vStrTheData[i].AccountNumber == AccountNumber)
		{
			found = true;
			FunPrintTheDataClientCard(vStrTheData, AccountNumber);
			cout << endl;

			cout << "ENTER HOW MANY YOU WANT ADD : ";
			cin >> deposit;

			test = stoi(vStrTheData[i].BalanceNumber);
			test += deposit;

			vStrTheData[i].BalanceNumber = to_string(test);
			cout << "\nDEPOSIT DONE SUCCESSFULLY! NEW BALANCE IS: " << vStrTheData[i].BalanceNumber << endl;

			break;
		}
	}

	if (!found)
	{
		cout << "THE ACCOUNT IS NOT EXIST.\n";
	}

	fstream ClientDataFile;
	ClientDataFile.open("MyFile.txt", ios::out);

	for (StrTheData& Client : vStrTheData)
	{
		ClientDataFile << FunConvertTheStructToLine(Client, "#//#") << endl;
	}

	ClientDataFile.close();


}

void FunEditTheWithdraw(vector<StrTheData>& vStrTheData, string AccountNumber)
{
	int Withdraw = 0;
	bool found = false;

	cout << "=====================================\n";
	cout << "=          WITHDRAW SCREEN          =\n";
	cout << "=====================================\n";

	for (int i = 0; i < vStrTheData.size(); i++)
	{
		if (vStrTheData[i].AccountNumber == AccountNumber)
		{
			found = true;

			FunPrintTheDataClientCard(vStrTheData, AccountNumber);
			cout << endl;

			cout << "ENTER THE AMOUNT YOU WANT TO WITHDRAW FROM YOUR BANK ACCOUNT: ";
			cin >> Withdraw;

			int balance = stoi(vStrTheData[i].BalanceNumber);


			if (Withdraw > balance)
			{
				cout << "\nAMOUNT EXCEEDS THE BALANCE.\n";
				cout << "YOU CAN WITHDRAW UP TO: " << balance << endl;
				return;
			}

			balance -= Withdraw;

			vStrTheData[i].BalanceNumber = to_string(balance);

			cout << "\nWITHDRAW DONE SUCCESSFULLY!\n";
			cout << "NEW BALANCE IS: " << vStrTheData[i].BalanceNumber << endl;


			fstream ClientDataFile;
			ClientDataFile.open("MyFile.txt", ios::out);

			for (StrTheData& Client : vStrTheData)
			{
				ClientDataFile << FunConvertTheStructToLine(Client, "#//#") << endl;
			}

			ClientDataFile.close();

			return;
		}
	}

	if (!found)
	{
		cout << "THE ACCOUNT IS NOT EXIST.\n";
	}
}

void FunCountTheTotalBalance(vector<StrTheData>& vStrTheData)
{
	int counter = 0;

	cout << "=====================================\n";
	cout << "=          TOTAL BALANCES           =\n";
	cout << "=====================================\n";

	for (int i = 0; i < vStrTheData.size(); i++)
	{
		counter += stoi(vStrTheData[i].BalanceNumber);
	}

	cout << "THE TOTAL BALANCES IS : " << counter << endl;;
}
//طباعة //
void FunPrintTheHeader()
{
	cout << "=====================================\n";
	cout << "|         MAIN MENUE SCREEN         |\n";
	cout << "=====================================\n";
	cout << "|[1] SHOW CLIENT LIST               |" << endl;
	cout << "|[2] AAD CLIENT                     |" << endl;
	cout << "|[3] DELETE CLIENT                  |" << endl;
	cout << "|[4] UPDATE CLIENT INFO             |" << endl;
	cout << "|[5] FIND CLIENT                    |" << endl;
	cout << "|[6] REMOVE ALL CLIENT              |" << endl;
	cout << "|[7] TRANSACTION                    |" << endl;
	cout << "|[8] EXIT                           |" << endl;
	cout << "=====================================\n";
}

void FunPrintTheTransactionTable()
{
	FunDeleteTheMainMenu();

	cout << "=====================================\n";
	cout << "|         MAIN MENUE SCREEN         |\n";
	cout << "=====================================\n";
	cout << "|[1] Deposit                        |" << endl;
	cout << "|[2] Withdraw                       |" << endl;
	cout << "|[3] Total Balance                  |" << endl;
	cout << "|[4] Main Menu                      |" << endl;
	cout << "=====================================\n";
	cout << "CHOOSE WHAT YOU WANT TO DO ? [1 / 4]\n";
}

int FunNumberOfOption()
{
	short NumberOfOption = 0;

	cin >> NumberOfOption;

	while (cin.fail())
	{
		cin.clear();

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "YOUR ENTERED IF FAILED ENTER AGAIN : ";
		cin >> NumberOfOption;
	}

	return NumberOfOption;
}

//تفريغ و إعادة ضبط //

void FunClearFile()
{
	fstream MyFile;

	string LocationFile = "MyFile.txt";

	MyFile.open(LocationFile, ios::out);

	cout << "ALL CLIENTS HAVE BEEN DELETED SUCCESSFULLY \n";

	MyFile.close();
}

void FunStartTheTransaction(vector <StrTheData>& vStrTheData)
{
	short NumberOfOption = FunNumberOfOption();

	EnTheTransactionChoice Choice = (EnTheTransactionChoice)NumberOfOption;

	string AccountNumber = "";

	switch (Choice)
	{
	case Deposit:
		FunDeleteTheMainMenu();
		AccountNumber = FunReadTheAccountNumber();
		FunEditTheDeposit(vStrTheData, AccountNumber);
		break;

	case Withdraw:
		FunDeleteTheMainMenu();
		AccountNumber = FunReadTheAccountNumber();
		FunEditTheWithdraw(vStrTheData, AccountNumber);
		break;

	case TotalBalance:
		FunDeleteTheMainMenu();
		FunPrintTheHeaderOfClient();
		FunPrintTheBodyOfClient(vStrTheData);
		FunCountTheTotalBalance(vStrTheData);
		break;

	case MainMenu:
		FunDeleteTheMainMenu();
		FunPrintTheHeader();
		FunStart(vStrTheData);
		break;
	}
}

void FunStart(vector <StrTheData>& vStrTheData)
{
	string AccountNumber = "";
	StrTheData TheData;

	short NumberOfOption = FunNumberOfOption();

	EnTheChoice Choice = (EnTheChoice)NumberOfOption;

	switch (Choice)
	{

	case ShowClientList:
		FunDeleteTheMainMenu();
		FunPrintTheHeaderOfClient();
		FunPrintTheBodyOfClient(vStrTheData);
		break;

	case AddNewClient:
		FunDeleteTheMainMenu();
		TheData = ReadTheData();
		FunSaveTheLineInFile(FunConvertTheStructToLine(TheData, "#//#"));
		break;

	case DeleteClient:
		FunDeleteTheMainMenu();
		AccountNumber = FunReadTheAccountNumber();
		vStrTheData = FunDeleteTheUser(vStrTheData, AccountNumber);
		break;

	case UpdateClientInfo:
		FunDeleteTheMainMenu();
		AccountNumber = FunReadTheAccountNumber();
		vStrTheData = FunUpdateTheData(vStrTheData, AccountNumber);
		break;

	case FindClient:
		FunDeleteTheMainMenu();
		AccountNumber = FunReadTheAccountNumber();
		FunPrintTheDataClientCard(vStrTheData, AccountNumber);
		break;

	case RemoveAllClient:
		FunDeleteTheMainMenu();
		FunClearFile();
		break;

	case Transaction:
		FunDeleteTheMainMenu();
		FunPrintTheTransactionTable();
		FunStartTheTransaction(vStrTheData);
		break;

	case Exit:
		FunDeleteTheMainMenu();
		cout << "THE END !";
		cout << endl;
		break;

	}
};

void FunDeleteTheMainMenu()
{
	system("cls");

}

void FunExitTheWindos()

{
	char Test = 'e';

	cout << "ENTER ANY BUTTON TO BACK TO MENUE : ";
	cin >> Test;

	if (true)
	{
		system("cls");
	}
}

int main()
{
	vector<StrTheData> vStrTheData;

	while (true)
	{
		system("cls");

		vStrTheData = FunReadTheLineFromFile();

		FunPrintTheHeader();

		cout << "CHOOSE WHAT YOU WANT TO DO ? [1 / 8]\n";

		FunStart(vStrTheData);

		system("pause");
	}

	return 0;
}