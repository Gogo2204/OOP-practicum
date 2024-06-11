#pragma once

#include "Monster.h"
#include "Minotavar.h"

int Minotavar::fight(const Monster* monster) const
{
	return monster->fightWithMinotavar(this);
}

int Minotavar::fightWithMinotavar(const Minotavar* other) const
{
	return 0;
}

int Minotavar::fightWithKentavar(const Kentavar* other) const
{
	return -1;
}

int Minotavar::fightWithSfinks(const Sfinks* other) const
{
	return 1;
}
