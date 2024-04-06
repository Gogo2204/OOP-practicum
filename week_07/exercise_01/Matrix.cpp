#include <iostream>
#include "Matrix.h";

void Matrix::copyFrom(const Matrix& other)
{
	rows = other.rows;
	colls = other.colls;

	for (size_t i = 0; i < rows; i++)
	{
		mtx[i] = other.mtx[i];
	}
}

void Matrix::free()
{
	for (size_t i = 0; i < rows; i++)
	{
		mtx[i].~Row();
	}
	delete[] mtx;
	mtx = nullptr;

	rows = 0;
	colls = 0;
}

int Matrix::multRowAndColl(const Matrix& mtx1, const Matrix& mtx2, size_t currentRow, size_t currentColl)
{
	int res = 0;
	for (size_t i = 0; i < mtx1.colls; i++)
	{
		res += (mtx1.mtx[currentRow].getRow()[i]) * (mtx2.mtx[i].getRow()[currentColl]);
	}
	return res;
}

Matrix::Matrix():Matrix(2,2) {}

Matrix::Matrix(size_t rows, size_t colls)
{
	rows = rows;
	colls = colls;

	mtx = new Row[rows]; 
	Row row(colls);

	for (size_t i = 0; i < rows; i++)
	{
		mtx[i] = row;
	}
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Matrix::~Matrix()
{
	free();
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	if (rows != other.rows || colls != other.colls)
		return *this;

	*this = *this + other;

	return *this;
}

Matrix Matrix::operator+(const Matrix& other) const
{
	Matrix res(other.rows, other.colls);

	for (size_t i = 0; i < rows; i++)
	{
		res.mtx[i] = mtx[i] + other.mtx[i];
	}

	return res;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (rows != other.rows || colls != other.colls)
		return *this;

	*this = *this - other;

	return *this;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	Matrix res(other.rows, other.colls);

	for (size_t i = 0; i < rows; i++)
	{
		res.mtx[i] = mtx[i] - other.mtx[i];
	}

	return res;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	Matrix mtx1 = *this;	

	*this = mtx1 * other;

	return *this;
}

Matrix Matrix::operator*(const Matrix& other)
{	
	Matrix res(rows, other.colls);	

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colls; j++)
		{
			res.mtx[i].setCell(multRowAndColl(*this, other, i, j), j);
		}
	}

	return res;
}

Matrix& Matrix::operator*=(size_t scalar)
{
	*this = *this * scalar;
	return *this;
}

Matrix Matrix::operator*(size_t scalar) const
{
	Matrix res(rows, colls);

	for (size_t i = 0; i < rows; i++)
	{
		res.mtx[i] *= scalar;
	}

	return res;
}

bool Matrix::operator==(const Matrix& other) const
{
	return !(*this != other);
}

bool Matrix::operator!=(const Matrix& other) const
{
	for (size_t i = 0; i < rows; i++)
	{
		if (mtx[i] != other.mtx[i])
			return true;
	}
	return false;
}
