#pragma once
#include <iostream>
#include <exception>

template <typename T>

class Vector
{
public:
	Vector()
	{
		size = 0;
		capacity = 8;
		data = new T[capacity];
	}

	Vector(size_t size)
	{
		this->size = 0;
		capacity = size;
		data = new T[capacity];
	}

	Vector(const Vector <T>& other)
	{
		copyFrom(other);
	}

	Vector<T>& operator=(const Vector<T>& other)
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}

	Vector(const Vector<T>&& other) noexcept
	{
		moveFrom(std::move(other));
	}

	Vector<T>& operator=(const Vector<T>&& other) noexcept
	{
		if (this != &other)
		{
			free();
			moveFrom(std::move(other));
		}
		return *this;
	}

	T& operator[](size_t index)
	{
		if (index >= size)
			throw std::out_of_range("The index is out of range!");
		return data[index];
	}
	const T& operator[](size_t index) const
	{
		if (index >= size)
			throw std::out_of_range("The index is out of range!");
		return data[index];
	}

	~Vector() noexcept
	{
		free();
	}

	void push_back(Vector<T>& elem)
	{
		if (size == capacity)
			resize();
		data[size++] = elem;
	}

	void push_back(Vector<T>&& elem) //noexcept?
	{
		if (size == capacity)
			resize();
		data[size++] = std::move(elem);
	}

	void pop_back()
	{
		if (isEmpty())
			throw std::logic_error("The vector is already empty!");
		size--;
	}

	void insert(const Vector<T>& elem, size_t index)
	{
		if (index >= size)
			throw std::out_of_range("The index is out of range!");

		if (size == capacity)
			resize();

		size++;
		for (int i = size - 1; i > index; i--)
			data[i] = data[i - 1];

		data[index] = elem;
	}

	void insert(const Vector<T>&& elem, size_t index)
	{
		if (index >= size)
			throw std::out_of_range("The index is out of range!");

		if (size == capacity)
			resize();

		size++;
		for (int i = size - 1; i > index; i--)
			data[i] = std::move(data[i - 1]);

		data[index] = std::move(elem);
	}

	void erase(size_t index)
	{
		if (index >= size)
			throw std::out_of_range("The index is out of range!");

		for (size_t i = index; i < size - 1; i++)
			data[i] = std::move(data[i + 1]);
		size--;
	}

	void clear()
	{
		free();
		capacity = 8;
		data = new T[capacity];
	}

	bool isEmpty() const
	{
		return size == 0;
	}

	size_t size() const
	{
		return this->size;
	}

private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const Vector<T>& other)
	{
		data = new T[other.size];
		for (size_t i = 0; i < other.size; i++)
		{
			data[i] = other.data[i];
		}
		size = other.size;
		capacity = other.capacity;
	}

	void moveFrom(const Vector<T>&& other)
	{
		data = other.data;
		other.data = nullptr;

		size = other.size;
		other.size = 0

			capacity = other.capacity;
		other.capacity = 0;
	}

	void free()
	{
		delete[] data;
		data = nullptr;
		size = 0;
		capacity = 0;
	}

	void resize()
	{
		size_t newCap = (capacity + 1) * 2;
		T* newData = new T[newCap];
		capacity = newCap - 1;

		for (size_t i = 0; i < size; i++)
		{
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
	}
};
