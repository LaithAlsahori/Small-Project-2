#include<iostream>
#include<cmath>
using namespace std;
struct StrTheData
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};
StrTheData FunReadThedate(StrTheData TheData)
{
	cout << "ENTER THE DAY : ";
	cin >> TheData.Day;

	cout << "ENTER THE MONTH : ";
	cin >> TheData.Month;

	cout << "ENTER THE YEAR : ";
	cin >> TheData.Year;

	return TheData;
}
bool FunIsTheLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}
short FunNumberOfDaysInMonth(short Month, short Year)
{
	if (Month == 2)
	{
		return (FunIsTheLeapYear(Year)) ? 29 : 28;
	}

	else if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
	{
		return 31;
	}

	return 30;
}
short FunConvertTheDataToDays(StrTheData TheData)
{
	short Counter = 0;

	while (TheData.Month > 0)
	{
		Counter += FunNumberOfDaysInMonth(TheData.Month, TheData.Year);

		TheData.Month--;
	}

	Counter += TheData.Day;

	return Counter;
}
short FunDiffrenceBtweenDates(StrTheData TheData1, StrTheData TheData2,bool IncludeEndDay = false)
{
	short num1 = 0, num2 = 0,TheDiffrence = 0;

	num1 = FunConvertTheDataToDays(TheData1);

	num2 = FunConvertTheDataToDays(TheData2);

	TheDiffrence = num1 - num2;

	return (IncludeEndDay) ? abs(TheDiffrence) + 1 : abs(TheDiffrence) ;


}
int main()
{
	StrTheData TheData1, TheData2;
	short TheDiffrence = 0;

	cout << "ENTER THE DATA TO DATE NUMBER 1 : \n";

	TheData1 = FunReadThedate(TheData1);

	cout << "\n\nENTER THE DATA TO DATE NUMBER 2 : \n";

	TheData2 = FunReadThedate(TheData2);

	TheDiffrence = FunDiffrenceBtweenDates(TheData1, TheData2);

	cout << endl <<"THE DIFFRENCE IS : " << TheDiffrence;

	TheDiffrence = FunDiffrenceBtweenDates(TheData1, TheData2,true); 

	cout << endl << "THE DIFFRENCE IS (with end day): " << TheDiffrence;

	return 0; 
}