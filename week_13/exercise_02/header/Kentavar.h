#pragma once

#include "Monster.h"

class Kentavar : public Monster
{
public:
	int fight(const Monster* monster) const override;
	int fightWithMinotavar(const Minotavar* other) const override;
	int fightWithKentavar(const Kentavar* other) const override;
	int fightWithSfinks(const Sfinks* other) const override;
};
