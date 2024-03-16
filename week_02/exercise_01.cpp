#include <iostream>
#include <fstream>

void writeInFile(const char* fileName, const int sum, const int mult)
{
	std::ofstream ofs(fileName);

	if (!ofs.is_open())
		return;

	ofs << sum << std::endl;
	ofs << mult << std::endl;

	ofs.close();
}

void readFromFile(const char* fileName, int& num1, int& num2)
{
	std::ifstream read(fileName);

	if (!read.is_open())
		return;

	read >> num1;
	read >> num2;

	read.close();
}

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	const constexpr char* FILE_NAME = "result.txt";

	int sum = a + b + c;
	int mult = a * b * c;

	writeInFile(FILE_NAME, sum, mult);

	int x, y;

	readFromFile(FILE_NAME, x, y);

	std::cout << x - y;
}