#pragma once

#include "Kentavar.h"

int Kentavar::fight(const Monster* monster) const
{
	return monster->fightWithKentavar(this);
}

int Kentavar::fightWithMinotavar(const Minotavar* other) const
{
	return 1;
}

int Kentavar::fightWithKentavar(const Kentavar* other) const
{
	return 0;
}

int Kentavar::fightWithSfinks(const Sfinks* other) const
{
	return -1;
}
