// Multidimensional Arrays
#include <iostream>

int convertToIndex(int row, int column, int width);

int main()
{
#if 0
	// All in stack - It is 1D array behind the scenes
	int array2d[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << array2d[i][j] << " ";
		}
		std::cout << "\n";
	}
#endif

#if 0
	// The pointer on stack, actual data on heap
	int* array2d[3];
	for (int i = 0; i < 3; ++i)
	{
		array2d[i] = new int[3];
	}

	// Insert values into the 2d array
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			array2d[i][j] = i * j;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << array2d[i][j] << " ";
		}
		std::cout << "\n";
	}

	for (int i = 0; i < 3; ++i)
	{
		delete[] array2d[i];
	}
#endif

#if 0
	// All on heap
	int** array2d;
	array2d = new int* [3];

	for (int i = 0; i < 3; ++i)
	{
		array2d[i] = new int[3];
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			array2d[i][j] = i * j;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << array2d[i][j] << " ";
		}
		std::cout << "\n";
	}
	for (int i = 0; i < 3; ++i)
	{
		delete[] array2d[i];
	}
	delete array2d;
#endif 

	// Matrix as a 1D array in the memory
	int nRows = 3;
	int nColumns = 3;

	int* array2d = new int[nRows * nColumns];

	for (int row = 0; row < nRows; ++row)
	{
		for (int column = 0; column < nColumns; ++column)
		{
			//array2d[column+row*nColumns] = row * column;

			array2d[convertToIndex(row, column, nColumns)] = row * column;
		}
	}
	for (int i = 0; i < nRows * nColumns; ++i)
	{
		std::cout << array2d[i] << " ";
		if (!((i + 1) % nColumns))
			std::cout << "\n";
	}
	delete[] array2d;


	return 0;
}

int convertToIndex(int row, int column, int width)
{
	return (column + row*width);
}