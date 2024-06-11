#pragma once

class Minotavar;
class Kentavar;
class Sfinks;

class Monster
{
public:

	virtual int fight(const Monster* monster) const = 0;
	virtual int fightWithMinotavar(const Minotavar* other) const = 0;
	virtual int fightWithKentavar(const Kentavar* other) const = 0;
	virtual int fightWithSfinks(const Sfinks* other) const = 0;

	virtual ~Monster() = default;
};
