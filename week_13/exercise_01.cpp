#include <iostream>

template <class T>
void sort(T* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		size_t minElement = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[minElement] > arr[j])
				minElement = j;
		}
		if (minElement != i)
			std::swap(arr[i], arr[minElement]);
	}
}

template<char*>
void sort(char* arr, size_t size)
{
	constexpr size_t newSize = 256;
	unsigned sortedArray[newSize] = {};

	for (size_t i = 0; i < size; i++)
	{
		if (i == arr[i])
			sortedArray[i]++;
	}

	size = 0;
	for (size_t i = 0; i < newSize; i++)
	{
		if (sortedArray[i] != 0)
		{
			while (!sortedArray[i])
			{
				arr[size++] = sortedArray[i];
			}
		}
	}
}
