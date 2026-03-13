#include<iostream>
#include<iomanip>
#include <ctime>
#include<cstdio>
using namespace std;
struct StrThe_Data
{
	int the_matrix[3][3];
	char play = 'y';
};
int FunRead_The_Random_Number(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
StrThe_Data FunFill_The_Matrix(StrThe_Data &The_Data)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			The_Data.the_matrix[i][j] = FunRead_The_Random_Number(0,100);
			cout << setw(20) << The_Data.the_matrix[i][j]<<" ";
		}
		cout << endl;
	}
	return The_Data;
}
void FunStart_The_Project(StrThe_Data The_Data)
{
	cout << "enter Y/y if you want start : ";
	cin >> The_Data.play;

	if (The_Data.play=='y' || The_Data.play == 'Y')
	{
		printf("you are enter : %c \n", The_Data.play);
		cout<<setw(50)<< "you random matrix is : \n";
		FunFill_The_Matrix(The_Data);
	}
	else
	{
		cout << "try again \n";
	}

}
int main()
{
	srand((unsigned)time(NULL));
	StrThe_Data The_Data;

	FunStart_The_Project(The_Data);

	return 0;
}