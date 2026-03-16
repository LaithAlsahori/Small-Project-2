#include<iostream>
#include<iomanip>
using namespace std;
struct StrThe_Data
{
	int row = 0;
	int col = 0;
	int** arr;

};
void FunCreate_2D_Array(StrThe_Data& The_Data)
{
	cout << "enter the number of row : ";
	cin >> The_Data.row;

	cout << "enter the number of column : ";
	cin >> The_Data.col;

	The_Data.arr = new int* [The_Data.row];

	for (int i = 0; i < The_Data.row; i++)
	{
		The_Data.arr[i] = new int[The_Data.col];
	}
}
void FunFill_2D_Array(StrThe_Data& The_Data)
{
	FunCreate_2D_Array(The_Data);

	int test = 0;

	for (int i = 0; i < The_Data.row; i++)
	{
		for (int j = 0; j < The_Data.col; j++)
		{
			test += 1;

			The_Data.arr[i][j] = test;
		}
	}
}
void FunPrint_The_Array(StrThe_Data& The_Data)
{

	for (int i = 0; i < The_Data.row; i++)
	{
		for (int j = 0; j < The_Data.col; j++)
		{
			cout << setw(15) << The_Data.arr[i][j] << "  ";
		}
		cout << endl;
	}
}
void FunPrint_The_Transpose_Array(StrThe_Data& The_Data)
{

	for (int i = 0; i < The_Data.col; i++)
	{
		for (int j = 0; j < The_Data.row; j++)
		{

			cout << setw(15) << The_Data.arr[j][i] << "  ";
		}
		cout << endl;
	}
}
int main()
{
	StrThe_Data The_Data;

	FunFill_2D_Array(The_Data);

	cout << "The Matrix : \n";
	FunPrint_The_Array(The_Data);


	cout << "\n\n\nThe Transpose Array : \n";
	FunPrint_The_Transpose_Array(The_Data);


	return 0;
}