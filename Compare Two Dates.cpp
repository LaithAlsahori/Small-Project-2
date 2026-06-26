#include<iostream>
using namespace std;
struct StrTheData
{
	short Days = 0;
	short Months = 0;
	short Years = 0;
	short TotalDays = 0;
};
StrTheData FunReadTheData(StrTheData TheData)
{
	cout << "ENTER THE DAY : ";
	cin >> TheData.Days;

	cout << "ENTER THE MONTH : ";
	cin >> TheData.Months;

	cout << "ENTER THE YEAR : ";
	cin >> TheData.Years;

	return TheData;
}
bool FunIsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}
short FunNumberOfDays(short Month,short Year)
{
	if (Month == 2)
	{
		return FunIsLeapYear(Year) ? 29 : 28;
	}

	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12 )
	{
		return 31;
	}

	return 30;
}
short FunConvertTheDateToNumber(short Day,short Month, short Year)
{
	short Number = 0;

	while (Month - 1 > 0)
	{
		Number += FunNumberOfDays(Month, Year);

		Month--;
    }

	Number += Day;

	return Number;
}
void FunStart()
{
	StrTheData TheData1, TheData2;

	TheData1 = FunReadTheData(TheData1);

	cout << endl;

	TheData2 = FunReadTheData(TheData2);

	TheData1.TotalDays = FunConvertTheDateToNumber(TheData1.Days, TheData1.Months, TheData1.Years);

	TheData2.TotalDays = FunConvertTheDateToNumber(TheData2.Days, TheData2.Months, TheData2.Years);

	cout << endl;

	if (TheData1.Years > TheData2.Years)
	{
		cout << "THE DATE 2 LESS THAN DATE 1 . ";
	}
	else if (TheData1.Years < TheData2.Years)
	{
		cout << "THE DATE 1 LESS THAN DATE 2 . ";
	}
	else
	{
		if (TheData1.TotalDays > TheData2.TotalDays)
		{
			cout << "THE DATE 2 LESS THAN DATE 1 . ";
		}
		else if (TheData1.TotalDays < TheData2.TotalDays)
		{
			cout << "THE DATE 1 LESS THAN DATE 2 . ";
		}
	}
}
int main()
{

	FunStart();

	return 0;
}