#include <iostream>
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

    for (short i = 1; i < Month; i++)
    {
        Counter += FunNumberOfDays(i, Year);
    }

    return Counter + Day;
}

void FunConvertTheDayAddedToDate(short AddDays, short Day, short Month, short Year)
{
    while (AddDays > 0)
    {
        short DaysRemaining = FunNumberOfDays(Month, Year) - Day;

        if (AddDays > DaysRemaining)
        {
            AddDays -= (DaysRemaining + 1);

            Day = 1;
            Month++;

            if (Month > 12)
            {
                Month = 1;
                Year++;
            }
        }
        else
        {
            Day += AddDays;
            AddDays = 0;
        }
    }

    cout << "[" << Day << "/" << Month << "/" << Year << "]";
}
int main()
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
    short AddDays;

    cout << "ENTER THE YEAR : ";
    cin >> Year;

    cout << "ENTER THE MONTH : ";
    cin >> Month;

    cout << "ENTER THE DAY : ";
    cin >> Day;

    short Result = FunCounterTheNumberOfDays(Day, Month, Year);

    cout << "\nTHE RESULT IS, NUMBER OF DAYS: " << Result << endl;

    cout << "ENTER HOW MANY DAYS DO YOU WANT ADD : ";
    cin >> AddDays;

    FunConvertTheDayAddedToDate(AddDays,Day, Month, Year);

    return 0;
}