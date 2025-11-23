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

void DeleteColumn(int**& arr, int rows, int& cols, int position)
{
    if (position < 0 || position >= cols) return;

    int** newArr = new int* [rows];
    for (int i = 0; i < rows; i++)
        newArr[i] = new int[cols - 1];

    for (int i = 0; i < rows; i++)
    {
        int newJ = 0;
        for (int j = 0; j < cols; j++)
        {
            if (j == position) continue;
            newArr[i][newJ++] = arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;

    arr = newArr;
    cols--;
}


int main()
{
    int rows = 4, cols = 7;

    int** A = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        A[i] = new int[cols];
    }

    FillArrayRandomly(A, rows, cols);
    PrintArray(A, rows, cols);
    int position = 0;
    cout << "Enter the position where you want to delete the column >>> ";
    cin >> position;
    DeleteColumn(A, rows, cols, position - 1);
    PrintArray(A, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}
