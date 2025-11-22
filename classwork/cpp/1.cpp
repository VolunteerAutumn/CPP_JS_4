#include <iostream>
#include <iomanip>
using namespace std;

// ______ basic functions so my fingers won't fuck up ______
void FillArray(int* arr, int size) 
{ 
	for (int i = 0; i < size; i++) 
	{ 
		arr[i] = rand() % 100; 
	} 
}

void PrintArray(int** arr, int rows, int cols) 
{ 
	for (int i = 0; i < rows; i++) 
	{ 
		cout << "|  ";
		for (int j = 0; j < cols; j++) 
		{ 
			cout << setw(3) << arr[i][j] << " "; 
		} 
		cout << "  |";
		cout << "\n"; 
	} 
}

// ______ TASK FUNCTIONS ______
void AddNewLine(int**& arr, int& rows, int cols)
{
	int** newArr = new int*[rows + 1];
	for (int i = 0; i < rows; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[rows] = new int[cols];

	for (int j = 0; j < cols; j++)
	{
		newArr[rows][j] = 0;
	}

	delete[] arr;
	arr = newArr;
	rows++;
}

// ______ TEST ______
int main()
{
	int cols = 12;
	int rows = 4;

	int** A = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		A[i] = new int[cols];
		FillArray(A[i], cols);
	}

	cout << "======================================================" << endl;
	PrintArray(A, rows, cols);
	cout << "======================================================" << endl;
	AddNewLine(A, rows, cols);
	PrintArray(A, rows, cols);
	cout << "======================================================" << endl;

	for (int i = 0; i < rows; i++)
		delete[] A[i];
	delete[] A;
}
