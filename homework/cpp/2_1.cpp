#include <iostream>
#include <iomanip>
using namespace std;

void FillArrayRandomly(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}

void PrintArray(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int** Transpose(int** Arr, int rows, int cols)
{
	int** T = new int* [cols];
	for (int i = 0; i < cols; i++)
	{
		T[i] = new int[rows];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			T[j][i] = Arr[i][j];
		}
	}

	return T;
}

int main()
{
    int rows = 3, cols = 3;

    int** A = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        A[i] = new int[cols];
    }

	FillArrayRandomly(A, rows, cols);
	PrintArray(A, rows, cols);
	cout << "==========================" << endl;
	int** B = Transpose(A, rows, cols);
	PrintArray(B, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}
