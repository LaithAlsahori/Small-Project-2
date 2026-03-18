#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;
int FunRead_The_Random_Number(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
int FunRead_The_Pos_Num()
{
	int num = 0;

	cout << "enter the pos number : ";
	do
	{
		cin >> num;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << "invalid number enter a valid one : " << endl;
			cin >> num;
        } 

	} while (num<0);

	return num;
}
void FunFill_The_Number(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{

			arr[i][j] = FunRead_The_Random_Number(1, 10);
		}
		
	}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	FunFill_The_Number(arr, Rows, Cols);

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
void FunChick_The_Number(int arr[3][3], short Rows, short Cols)
{
	int num = FunRead_The_Pos_Num();
	int count = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{

			if (arr[i][j] == num)
			{
				count++;
			}
		}
		
	}
	cout << "your number " << num << " is repeated : " << count << " time \n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FunChick_The_Number(Matrix1, 3, 3);
	
	system("pause>0");
}