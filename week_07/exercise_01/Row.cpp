#pragma once

#include <iostream>
#include "Row.h"

void Row::copyFrom(const Row& other)
{
	colls = other.colls;
	for (size_t i = 0; i < colls; i++)
	{
		row[i] = other.row[i];
	}
}

void Row::free()
{
	delete[] row;
	row = nullptr;
	colls = 0;
}

Row::Row():Row(2) {}

Row::Row(size_t colls)
{
	this->colls = colls;
	row = new int[colls] {};
}

Row& Row::operator=(const Row& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Row::~Row()
{
	free();
}

const int* Row::getRow() const
{
	return row;
}

void Row::setCell(int value, size_t index)
{
	row[index] = value;
}

Row& Row::operator+=(const Row& other)
{
	*this = *this + other;
	return *this;
}

Row Row::operator+(const Row& other) const
{
	Row res(other.colls);

	for (size_t i = 0; i < colls; i++)
	{
		res.row[i] = row[i] + other.row[i];
	}

	return res;
}

Row& Row::operator-=(const Row& other)
{
	*this = *this - other;
	return *this;
}

Row Row::operator-(const Row& other) const
{
	Row res(other.colls);

	for (size_t i = 0; i < other.colls; i++)
	{
		res.row[i] = row[i] - other.row[i];
	}

	return res;
}

Row& Row::operator*=(size_t scalar)
{
	*this = *this * scalar;
	return *this;
}

Row Row::operator*(size_t scalar) const
{
	Row res(colls);

	for (size_t i = 0; i < colls; i++)
	{
		res.row[i] *= scalar;
	}

	return res;
}

bool Row::operator==(const Row& other) const
{
	return !(*this != other);
}

bool Row::operator!=(const Row& other) const
{
	for (size_t i = 0; i < colls; i++)
	{
		if (row[i] != other.row[i])
			return true;
	}
	return false;
}
