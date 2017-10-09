#include "Character.h"

Character::Character(std::string Name)
{
	*name = Name;
	currHealth = NULL;
	attackPoint = NULL;
	defensePoint = NULL;
}

Character::Character(std::string Name, int initialHealth, int initialAtk, int initialDef)
{
	*name = Name;
	*currHealth = initialHealth;
	*attackPoint = initialAtk;
	*defensePoint = initialDef;
}

Character::~Character()
{
	delete currHealth;
	delete attackPoint;
	delete defensePoint;
}

int Character::getHealth()
{
	return *currHealth;
}

void Character::setHealth(int newHealth)
{
	*currHealth = newHealth;
	if (this->getHealth() > 100)
	{
		*currHealth = 100;
	}
}

int Character::getAtk()
{
	return *attackPoint;
}

void Character::addAtk(int addition)
{
	*attackPoint += addition;
	if (this->getAtk() > 10)
	{
		*attackPoint = 10;
	}
}

int Character::getDef()
{
	return *defensePoint;
}

void Character::addDef(int addition)
{
	*defensePoint += addition;
	if (this->getDef() > 10)
	{
		*defensePoint = 10;
	}
}

