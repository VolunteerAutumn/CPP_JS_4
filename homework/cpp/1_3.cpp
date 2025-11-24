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

void ShiftRow(int* row, int cols, int k, bool toRight)
{
    k %= cols;
    if (k == 0) return;

    int* temp = new int[cols];

    for (int j = 0; j < cols; j++)
    {
        int newPos = toRight ? (j + k) % cols : (j - k + cols) % cols;
        temp[newPos] = row[j];
    }

    for (int j = 0; j < cols; j++)
        row[j] = temp[j];

    delete[] temp;
}

void ShiftColumn(int** arr, int rows, int colIndex, int k, bool down)
{
    k %= rows;
    if (k == 0) return;

    int* temp = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        int newPos = down ? (i + k) % rows : (i - k + rows) % rows;
        temp[newPos] = arr[i][colIndex];
    }

    for (int i = 0; i < rows; i++)
        arr[i][colIndex] = temp[i];

    delete[] temp;
}

void ShiftColumnsOr_AndRows(int**& arr, int rows, int cols,  bool rowshift, bool colshift, int amount, bool direction)
{
    /* direction:
     rows: true = right, false = left
     cols: true = down,  false = up */
    if (rowshift)
    {
        for (int i = 0; i < rows; i++)
            ShiftRow(arr[i], cols, amount, direction);
    }

    if (colshift)
    {
        for (int j = 0; j < cols; j++)
            ShiftColumn(arr, rows, j, amount, direction);
    }
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
    ShiftColumnsOr_AndRows(A, rows, cols, true, false, 4, false);
    PrintArray(A, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}
