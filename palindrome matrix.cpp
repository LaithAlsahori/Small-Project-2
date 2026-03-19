#include<iostream>
#include<iomanip>
using namespace std;
void FunPrint_The_Number(int arr[3][3],int row,int col)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << setw(10) << arr[i][j];
		}
		cout << endl;
	}
}
bool FunThe_Matrix_Is_Palindrome(int arr[3][3], int row, int col)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (arr[i][0] != arr[i][col - j - 1])
			{
				return false;
			}
		}
		
	}
	return true;
}
int main()
{
	int matrix[3][3] = { {1,1,1},{1,1,1},{1,1,1} };

	cout << setw(28) << "your matrix : \n\n";
	FunPrint_The_Number(matrix,3,3);

	if (FunThe_Matrix_Is_Palindrome(matrix, 3, 3))
	{
		cout << "your matrix is palindrome \n";
	}
	else
	{
		cout << "your matrix is not palindrome \n";
	}
	return 0;
}