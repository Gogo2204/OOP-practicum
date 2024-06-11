#include <iostream>
#include "Monster.h"
#include "Minotavar.h"
#include "Kentavar.h"
#include "Sfinks.h"
#include <cstdlib>

int main()
{
    Monster* monsters[15];

	for (size_t i = 0; i < 15; i++)
	{
		unsigned random = rand() % 3;

		if (random == 0)
		{
			monsters[i] = new Minotavar;
		}
		else if (random == 1)
		{
			monsters[i] = new Kentavar;
		}
		else
		{
			monsters[i] = new Sfinks;
		}
	}

	size_t index = rand() % 15;
	unsigned winsCount = 0;

	for (size_t i = 0; i < 15; i++)
	{
		if (monsters[i]->fight(monsters[index]) == 1)
			winsCount++;
	}

	std::cout << winsCount;
}
