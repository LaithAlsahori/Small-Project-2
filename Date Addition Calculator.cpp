#include<iostream>
#include <cmath>
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
short FunNumberOfDaysInMonth(short Month,short Year)
{
	if (Month == 2)
	{
		return (FunIsLeapYear(Year)) ? 29 : 28;
	}

	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
	{
		return 31;
	}

	return 30;
}
void FunStart(short Day,short Month,short Year)
{
	short Number = 0;

	cout << "ENTER HOW MANY DAYS DO YOU WANT ADD : ";
	Number = FunReadTheNumber();

	Day += Number;

	while (Day > FunNumberOfDaysInMonth(Month,Year))
	{
		
		Day -= FunNumberOfDaysInMonth(Month, Year);

		Month++;
		
		if (Month > 12)
		{
			Month = 1;
			Year++;
		}
	}

	cout << "THE NEW DATE : [" << Day << "/" << Month << "/" << Year << "]";
}
int main()
{
	short Day = 0,Month = 0,Year = 0;

	cout << "ENTER THE DAYS : ";
	Day = FunReadTheNumber();

	cout << "ENETR THE MONTH : ";
	Month = FunReadTheNumber();

	cout << "ENERT THE YEAR : ";
	Year = FunReadTheNumber();

	cout << "THE OLD DATE : [" << Day << "/" << Month << "/" << Year << "]\n\n";

	FunStart(Day,Month,Year);

	cout << endl;


	return 0;
}