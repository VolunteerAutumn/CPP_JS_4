#include <iostream>
#include <iomanip>
using namespace std;

void FillArrayRandomly(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
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

int main()
{
	int cols = 0, rows = 0;
	cout << "Enter the amount of rows >>> ";
	cin >> rows;
	cout << "Enter the amount of cols >>> ";
	cin >> cols;

	int** A = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		A[i] = new int[cols];
	}

	int** B = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		B[i] = new int[cols];
	}

	FillArrayRandomly(A, rows, cols);
	FillArrayRandomly(B, rows, cols);

	PrintArray(A, rows, cols);
	cout << endl;
	PrintArray(B, rows, cols);

	int** C = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		C[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	cout << endl;
	PrintArray(C, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] A[i];
		delete[] B[i];
		delete[] C[i];
	}

	delete[] A;
	delete[] B;
	delete[] C;
}
