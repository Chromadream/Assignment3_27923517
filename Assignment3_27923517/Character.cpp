#include "Character.h"

Character::Character()
{
	name = NULL;
	currHealth = NULL;
	attackPoint = NULL;
	defensePoint = NULL;
}

Character::Character(std::string Name)
{
	name = &Name;
	currHealth = NULL;
	attackPoint = NULL;
	defensePoint = NULL;
}

Character::Character(std::string Name, int initialHealth, int initialAtk, int initialDef)
{
	name = new std::string(Name);
	currHealth = new int(initialHealth);
	attackPoint = new int(initialAtk);
	defensePoint = new int(initialDef);
}

Character::~Character()
{
	delete name;
	delete currHealth;
	delete attackPoint;
	delete defensePoint;
}

std::string Character::getName()
{
	return *name;
}

int Character::getHealth()
{
	return *currHealth;
}

void Character::addHealth(int addition)
{
	*currHealth += addition;
	if (this->getHealth() > 100)
	{
		*currHealth = 100;
	}
}

bool Character::decHealth(int subtraction)
{
	bool dead = false;
	if (subtraction > 0)
	{
		*currHealth -= subtraction;
	}
	if (this->getHealth() <= 0)
	{
		dead = true;
	}
	return dead;
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

std::ostream & operator<<(std::ostream & os, const Character & chara)
{
	double charaHealth = ceil((double)(*chara.currHealth)/10);
	double healthRem = 10 - charaHealth;
	os << *chara.name << std::endl;
	os << std::string(12, '-') << std::endl;
	os << "|" << std::string(charaHealth, '*')<<std::string(healthRem,' ')<<"|" << std::endl;
	os << std::string(12, '-') << std::endl;
	return os;
}
