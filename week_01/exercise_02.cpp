#include <iostream>

struct Complex
{
	int real;
	int imaginary;
};

Complex sum(const Complex& first, const Complex& second)
{
	Complex res = { 0, 0 };
	res.real = first.real + second.real;
	res.imaginary = first.imaginary + second.imaginary;
	return res;
}

Complex mult(const Complex& first, const Complex& second)
{
	Complex res = { 1, 1 };
	res.real = first.real * second.real - first.imaginary * second.imaginary;
	res.imaginary = first.real * second.imaginary + first.imaginary * second.real;
	return  res;
}

void printNum(const Complex& num)
{
	std::cout << num.real << " " << num.imaginary << std::endl;;
}

int main()
{
	Complex num1 = { 3, 4 }; // 3 + 4i
	Complex num2 = { 1, -2 }; // 1 - 2i

	Complex sumResult = sum(num1, num2);
	printNum(sumResult);

	Complex multResult = mult(num1, num2);
	printNum(multResult);
}