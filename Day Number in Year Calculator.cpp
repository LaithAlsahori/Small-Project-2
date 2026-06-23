#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
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
short FunCounterTheNumberOfDays(short Day, short Month, short Year)
{
    short Counter = 0;

    for (int i = 1; i < Month; i++)
    {
        Counter += FunNumberOfDays(i, Year);
    }

    return Counter + Day;
}
int main()
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
    short Result = 0;

    cout << "ENETR THE YEAR : ";
    cin >> Year;

    cout << "ENTER THE MONTH : ";
    cin >> Month;

    cout << "ENETR THE DAYS : ";
    cin >> Day;


    Result = FunCounterTheNumberOfDays(Day, Month, Year);
    cout << "\n THE RESULT IS , NUMBER OF DAYS : " << Result << endl;

    return 0;
}