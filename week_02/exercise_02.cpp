#include <iostream>
#include <fstream>

struct Pair
{
	unsigned first;
	unsigned second;
};

struct Relation
{
	size_t sizeOfSct;
	Pair pairs[25];
};

void writePairToFile(std::ofstream& write, const Pair& pair)
{
	if (!write.is_open())
		return;

	write << pair.first << std::endl;
	write << pair.second << std::endl;
}

void readPairFromFile(std::ifstream& read, Pair& pair)
{
	if (!read.is_open())
		return;

	read >> pair.first;
	read >> pair.second;
}

void writeRelationToFile(const char* fileName, const Relation& relation)
{
	std::ofstream write(fileName);

	if (!write.is_open())
		return;

	for (size_t i = 0; i < relation.sizeOfSct; i++)
	{
		writePairToFile(write, relation.pairs[i]);
	}

	write.close();
}

void readRelationFromFile(const char* fileName, Relation& relation)
{
	std::ifstream read(fileName);

	if (!read.is_open())
		return;

	for (size_t i = 0; i < relation.sizeOfSct; i++)
	{
		readPairFromFile(read, relation.pairs[i]);
	}

	read.close();
}

void addPairToRelation(Relation& relation, const Pair& pair)
{
	relation.pairs->first = pair.first;
	relation.pairs->second = pair.second;
}

void printRelation(const Relation& relation)
{
	for (size_t i = 0; i < relation.sizeOfSct; ++i) {
		std::cout << "Pair " << i + 1 << ": " << relation.pairs[i].first << ", " << relation.pairs[i].second << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	Relation testRelation;
	testRelation.sizeOfSct = 0;

	Pair pair1 = { 1, 2 };
	Pair pair2 = { 3, 4 };
	Pair pair3 = { 5, 6 };

	addPairToRelation(testRelation, pair1);
	addPairToRelation(testRelation, pair2);
	addPairToRelation(testRelation, pair3);

	writeRelationToFile("test.txt", testRelation);

	Relation readRelation;
	readRelation.sizeOfSct = testRelation.sizeOfSct;
	readRelationFromFile("test.txt", readRelation);

	printRelation(readRelation);
}