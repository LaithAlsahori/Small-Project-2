#include<iostream>
#include<ctime>
#include<cstdio>
#include<iomanip>
using namespace std;
struct StrThe_Data
{
	int** the_matrix;
	int row = 0;
	int column = 0;
	int sum = 0;
	int arr[10];

};
int FunRead_The_Random_Number(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
int FunRead_The_Pos_Num()
{
	int num = 0;

	do
	{
		cin >> num;

		if (cin.fail())
		{
			cin.clear();

			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "try again : ";

			cin >> num;
		}
	} while (num < 0);

	return num;
}
void FunRead_The_Size_Of_Matrix(StrThe_Data& The_Data)
{

	cout << "enter the number of row : ";

	The_Data.row = FunRead_The_Pos_Num();

	cout << "enter the number of column : ";

	The_Data.column = FunRead_The_Pos_Num();

	The_Data.the_matrix = new int* [The_Data.row];

	for (int i = 0; i < The_Data.row; i++)
	{
		The_Data.the_matrix[i] = new int[The_Data.column];
	}

}
void FunFill_The_Matrix(StrThe_Data& The_Data)
{
	FunRead_The_Size_Of_Matrix(The_Data);

	for (int i = 0; i < The_Data.row; i++)
	{
		for (int j = 0; j < The_Data.column; j++)
		{
			The_Data.the_matrix[i][j] = FunRead_The_Random_Number(1, 100);
		}
	}
}
int FunThe_Sum_Element_Of_Matrix(StrThe_Data& The_Data)
{
	for (int i = 0; i < The_Data.row; i++)
	{
		The_Data.sum = 0;

		for (int j = 0; j < The_Data.column; j++)
		{
			The_Data.sum += The_Data.the_matrix[i][j];
		}
		cout << "Sum of the numbers in row [" << i + 1 << "] : " << The_Data.sum << "\n";
	}
	return The_Data.sum;
}
void FunFill_The_Array_Of_Result_Row(StrThe_Data& The_Data)
{
	for (int i = 0; i < The_Data.row; i++)
	{
		int sum = 0;
		for (int j = 0; j < The_Data.column; j++)
		{
			sum += The_Data.the_matrix[i][j];
		}
		The_Data.arr[i] = sum;

	}
}
void FunPrint_The_Array_Data_Row(StrThe_Data& The_Data)
{

	FunFill_The_Array_Of_Result_Row(The_Data);

	cout << "\nThe Result Array Row: ";

	for (int i = 0; i < The_Data.row; i++)
	{
		cout << The_Data.arr[i] << " ";
	}
}
void FunFill_The_Array_Of_Result_Col(StrThe_Data& The_Data)
{
	for (int j = 0; j < The_Data.column; j++)
	{
		int sum = 0;

		for (int i = 0; i < The_Data.row; i++)
		{
			sum += The_Data.the_matrix[i][j];
		}

		The_Data.arr[j] = sum;
	}
}
void FunPrint_The_Array_Col(StrThe_Data& The_Data)
{
	FunFill_The_Array_Of_Result_Col(The_Data);

	cout << "\nThe Result Array Column: ";

	for (int j = 0; j < The_Data.column; j++)
	{
		cout << The_Data.arr[j] << " ";
	}
}
void FunPrint_The_Matrix(StrThe_Data& The_Data)
{
	FunFill_The_Matrix(The_Data);

	for (int i = 0; i < The_Data.row; i++)
	{
		for (int j = 0; j < The_Data.column; j++)
		{
			cout << setw(20) << The_Data.the_matrix[i][j];
		}
		cout << "\n\n";
	}
}
void FunStart_The_Program()
{
	StrThe_Data The_Data;
	char test = 'y';

	cout << "enter Y/y if you want start : ";

	cin >> test;

	if (test == 'y' || test == 'Y')
	{
		printf("you are enter : %c \n\n\n", test);
		FunPrint_The_Matrix(The_Data);
	}
	else
	{
		cout << "try again \n";
	}
	FunThe_Sum_Element_Of_Matrix(The_Data);
	FunPrint_The_Array_Data_Row(The_Data);
	FunPrint_The_Array_Col(The_Data);

}
void FunDelete_Matrix(StrThe_Data& The_Data)
{
	for (int i = 0; i < The_Data.row; i++)
	{
		delete[] The_Data.the_matrix[i];
	}

	delete[] The_Data.the_matrix;
}
int main()
{

	FunStart_The_Program();

	return 0;
}