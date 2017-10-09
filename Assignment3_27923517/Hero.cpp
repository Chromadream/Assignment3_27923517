#include "Hero.h"

Hero::Hero(std::string Name):
	Special(Name)
{
	*currHealth = 20;
	*attackPoint = 3;
	*defensePoint = 3;
	*specialAtk = 2;
	*prizeMoney = 0;
}

Hero::~Hero()
{
	delete prizeMoney;
}

void Hero::setHealth(int newHealth)
{
	*currHealth = newHealth;
	if (this->getHealth() > 50)
	{
		*currHealth = 50;
	}
}

void Hero::addPrizeMoney()
{
	*prizeMoney += 20;
}

int Hero::returnPrizeMoney()
{
	return *prizeMoney;
}
