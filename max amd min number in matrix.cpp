#include<iostream>
#include <ctime>
#include<iomanip>
using namespace std;
int FunRead_The_Random_Number(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
void FunFill_The_Number(int arr[3][3],int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = FunRead_The_Random_Number(1,20);
		}
	}
}
void FunPrint_The_Number(int arr[3][3],int row, int col)
{
	FunFill_The_Number(arr,3, 3);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(10) << arr[i][j];
		}
		cout << endl;
	}
}
int FunCheck_Max_Number_In_Matrix(int arr[3][3], int row, int col)
{
	int max = arr[0][0];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (max < arr[i][j])
			{
				max= arr[i][j];
			}

		}
	
	}
	return max;
}
int FunCheck_Min_Number_In_Matrix(int arr[3][3], int row, int col)
{
	int min = arr[0][0];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
			}

		}

	}
	return min;
}
int main()
{
	srand((unsigned)time(NULL));

	int matrix1[3][3];
	int matrix2[3][3];

	cout << "your matrix 1 is : \n\n";
	FunPrint_The_Number(matrix1, 3, 3);

	/*cout << "your matrix 1 is : \n\n";
	FunPrint_The_Number(matrix2, 3, 3);*/

	cout << endl;

	cout << "the max number in your matrix is : "<< FunCheck_Max_Number_In_Matrix(matrix1,3,3);
	cout << "\nthe min number in your matrix is :" << FunCheck_Min_Number_In_Matrix(matrix1, 3, 3);


	return 0;
}