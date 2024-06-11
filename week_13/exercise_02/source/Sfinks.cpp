#pragma once

#include "Sfinks.h"

int Sfinks::fight(const Monster* monster) const
{
	return monster->fightWithSfinks(this);
}

int Sfinks::fightWithMinotavar(const Minotavar* other) const
{
	return -1;
}

int Sfinks::fightWithKentavar(const Kentavar* other) const
{
	return 1;
}

int Sfinks::fightWithSfinks(const Sfinks* other) const
{
	return 0;
}
