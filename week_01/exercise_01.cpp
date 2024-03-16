#include <iostream>

int** createMtx(size_t rows, size_t colls)
{
	int** mtx = new int* [rows];

	for (size_t i = 0; i < rows; i++)
	{
		mtx[i] = new int[colls];
	}

	return mtx;
}

void freeMtx(int** mtx, size_t rows)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] mtx[i];
	}

	delete[] mtx;
}

void inputMtx(int** mtx, const size_t rows, const size_t colls)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colls; j++)
		{
			std::cin >> mtx[i][j];
		}
	}
}

void printMtx(int** mtx, const size_t rows, const size_t colls)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colls; j++)
		{
			std::cout << mtx[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int** findTransponirana(int** mtx, size_t rows, size_t colls)
{
	int** tran = createMtx(colls, rows);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colls; j++)
		{
			tran[j][i] = mtx[i][j];
		}
	}
	return tran;
}

void switchRows(int** mtx, const size_t row1, const size_t row2)
{
	std::swap(mtx[row1], mtx[row2]);
}

int main()
{
	size_t N, M;
	std::cin >> N >> M;

	int** mtx = createMtx(N, M);
	inputMtx(mtx, N, M);
	int** tran = findTransponirana(mtx, N, M);

	freeMtx(mtx, N);

	switchRows(tran, 0, 3);

	printMtx(tran, M, N);

	freeMtx(tran, M);
}