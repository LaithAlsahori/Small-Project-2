#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int FunReadTheNumber()
{
	int num = 0;

	cin >> num;

	return num;
}
string FunReaturnTheMonthName(int Number)
{
    string ArrayMonthName[] = {
    "JAN",
    "FEB",
    "MAR",
    "APR",
    "MAY",
    "JUN",
    "JUL",
    "AUG",
    "SEP",
    "OCT",
    "NOV",
    "DEC"
    };

    return ArrayMonthName[Number-1];
}
short FunDayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
        / 12)) % 7;
}
bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short FunNumberOfDays(short Month, short Year)
{
    if (Month == 2)
    {
        return isLeapYear(Year) ? 29 : 28;
    }

    if (Month == 1 || Month == 3 || Month == 5 ||
        Month == 7 || Month == 8 || Month == 10 || Month == 12)
    {
        return 31;
    }

    return 30;
}
void FunPrintTable(short Month, short Year)
{
    short Space = FunDayOfWeekOrder(1, Month, Year);

    short day = FunNumberOfDays(Month,Year);

    printf("==========[%s]==========\n", FunReaturnTheMonthName(Month).c_str());

    cout << "SUN  MON  TUE  WED  THU  FRI  SAT\n";
    for (int i = 0; i < Space; i++)
    {
        cout << "    ";
    }
        for (int j = 1; j <= day; j++)
        {
            cout << setw(5) << j;

            if ((j + Space) % 7 == 0)
            {
                cout << endl;
            }
        }
    
}
int main()
{
    short Year = 0;
    short Month = 1;

    cout << "ENETR THE YEAR : ";
    cin >> Year;

    while (Month <= 12)
    {
        FunPrintTable(Month, Year);

        Month++;

        cout << endl << endl;
    }
	return 0;
}