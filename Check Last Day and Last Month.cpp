#include<iostream>
using namespace std;
short FunReadTheNumber()
{
	short Number = 0;

	cin >> Number;

	return Number;
}
bool FunIsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}
short FunNumberOfDays(short Month , short Year)
{
	if (Month == 2)
	{
		return (FunIsLeapYear(Year)) ? 29 : 28;
	}

	else if (Month == 1 || Month == 3 || Month == 5 ||
		Month == 7 || Month == 8 || Month == 10 ||
		Month == 12)
	{
		return 31;
	}

	return 30;
}
bool FunIsLastDayInMonth(short Day,short Month,short Year)
{

	short TestDay = FunNumberOfDays(Month, Year);

	if (TestDay == Day)
	{
		return true;
    }
	else
	{
		return false;
	}
}
bool FunIsLastDayInYear(short Month)
{
	if (Month == 12)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void FunStart(short Day, short Month, short Year)
{
	cout << (FunIsLastDayInMonth(Day, Month, Year)
		? "YES, THE DAY IS THE FINAL DAY IN MONTH"
		: "NO, THE DAY ISN'T THE FINAL DAY IN MONTH");

	cout << endl;

	cout << (FunIsLastDayInYear(Month)
		? "YES, THE MONTH IS THE FINAL MONTH IN YEAR"
		: "NO, THE MONTH ISN'T THE FINAL MONTH IN YEAR");
}
int main()
{
	short Day = 0,Month = 0,Year = 0;

	cout << "ENTER THE DAY : ";
	Day = FunReadTheNumber();

	cout << "ENETR THE MONTH : ";
	Month = FunReadTheNumber();

	cout << "ENTER THE YEAR : ";
	Year = FunReadTheNumber();


	FunStart(Day, Month, Year);

	return 0;
}