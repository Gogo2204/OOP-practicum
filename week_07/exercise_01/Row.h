#pragma once

class Row
{
private:
	size_t colls = 0;
	int* row = nullptr;

	void copyFrom(const Row& other);
	void free();
public:
	Row();
	Row(size_t colls);
	Row& operator=(const Row& other);
	~Row();

	const int* getRow() const;
	void setCell(int value, size_t index);

	Row& operator+=(const Row& other);
	Row operator+(const Row& other) const;

	Row& operator-=(const Row& other);
	Row operator-(const Row& other) const;	

	Row& operator*=(size_t scalar);
	Row operator*(size_t scalar) const;

	bool operator==(const Row& other) const;
	bool operator!=(const Row& other) const;
};
