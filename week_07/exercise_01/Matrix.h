#pragma once

#include "Row.h"

class Matrix
{
private:	
	size_t rows = 0;
	size_t colls = 0;
	Row* mtx = nullptr;

	void copyFrom(const Matrix& other);
	void free();

	int multRowAndColl(const Matrix& mtx1, const Matrix& mtx2, size_t currentRow, size_t currentColl);

public:
	Matrix();
	Matrix(size_t rows, size_t colls);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix& operator+=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;

	Matrix& operator-=(const Matrix& other);
	Matrix operator-(const Matrix& other) const;

	Matrix& operator*=(const Matrix& other);
	Matrix operator*(const Matrix& other);

	Matrix& operator*=(size_t scalar);
	Matrix operator*(size_t scalar) const;

	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other) const;
};
