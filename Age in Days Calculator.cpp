#include<iostream>
using namespace std;
struct StrTheData
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
	int TotalDays = 0;
};
StrTheData FunReadTheNumber(StrTheData TheData)
{
	cout << "ENTER THE DAY : ";
	cin >> TheData.Day;

	cout << "ENTER THR MONTH : ";
	cin >> TheData.Month;

	cout << "ENTER THE YEAR : ";
	cin >> TheData.Year;

	return TheData;
}
bool FunIsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}
short FunNumberOfDayInMonth(short Month, short Year)
{
	if (Month == 2)
	{
		return ((FunIsLeapYear(Year))) ? 29 : 28;
	}

	if (Month == 1 || Month == 3 || Month == 5 ||
		Month == 7 || Month == 8 || Month == 10 ||
		Month == 12)
	{
		return 31;
	}

	return 30;
}
short FunConvertTheDateToDays(short Day, short Month, short Year)
{
	int Counter = 0;

	for (int y = 1; y < Year; y++)
	{
		Counter += FunIsLeapYear(y) ? 366 : 365;
	}

	for (int i = 1 ; i < Month ; i++)
	{
		Counter += FunNumberOfDayInMonth(i, Year);
	}

	Counter += Day;

	return Counter;
}
int main()
{
	StrTheData BirthDay;
	
	short TodayDate = 0;

	BirthDay = FunReadTheNumber(BirthDay);

	BirthDay.TotalDays = FunConvertTheDateToDays(BirthDay.Day, BirthDay.Month, BirthDay.Year);
	TodayDate = FunConvertTheDateToDays(27, 6, 2026);

	int FinalDays = TodayDate - BirthDay.TotalDays;

	cout << "\n THE NUMBER OF DAYS YOU HAVE : " << FinalDays << endl;

	return 0;
}