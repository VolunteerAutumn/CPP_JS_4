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
void DelRowByNumbah(int**& arr, int& rows, int cols, int row)
{
	// safety sheck
	if (row < 0 || row >= rows)
	{
		return;
	}
	delete[] arr[row];
	int** newArr = new int* [rows-1];
	for (int i = 0, j = 0; i < rows; i++)
	{
		if (i != row)
		{
			newArr[j++] = arr[i];
		}
	}

	delete[] arr;
	arr = newArr;
	rows--;
}

// ______ TEST ______
int main()
{
	int cols = 12;
	int rows = 4;
	int position = 0;

	int** A = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		A[i] = new int[cols];
		FillArray(A[i], cols);
	}

	cout << "On which position do I delete a row? (0 - 4) >>> ";
	cin >> position;

	cout << "======================================================" << endl;
	PrintArray(A, rows, cols);
	cout << "======================================================" << endl;
	DelRowByNumbah(A, rows, cols, position-1);
	PrintArray(A, rows, cols);
	cout << "======================================================" << endl;

	for (int i = 0; i < rows; i++)
		delete[] A[i];
	delete[] A;
}
