#include "Hero.h"

Hero::Hero() : Special()
{
	*prizeMoney = 0;
}

Hero::Hero(std::string Name):
	Special(Name,20,3,3,2)
{
	prizeMoney = new int(0);
}

Hero::Hero(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk): 
	Special(Name, initialHealth, initialAtk, initialDef, SpecialAtk)
{
	prizeMoney = new int(0);
}

Hero::~Hero()
{
	delete prizeMoney;
}

void Hero::addHealth(int addition)
{
	*currHealth += addition;
	if (this->getHealth() > 50)
	{
		*currHealth = 50;
	}
}

void Hero::addPrizeMoney(int money)
{
	*prizeMoney += money;
}

int Hero::returnPrizeMoney()
{
	return *prizeMoney;
}

std::ostream & operator<<(std::ostream & os, const Hero & chara)
{
	double charaHealth = (*chara.currHealth) / 10;
	double healthRem = 10 - charaHealth;
	os << "Stats of: " << (*chara.name) << std::endl;
	os << std::string(12, '-') << std::endl;
	os << "|" << std::string(charaHealth, '*') << std::string(healthRem, ' ') << "|" << std::endl;
	os << std::string(12, '-') << std::endl;
	os << "Attack: " << (*chara.attackPoint) << std::endl;
	os << "Defense: " << (*chara.defensePoint) << std::endl;
	os << "Special: " << (*chara.specialAtk) << std::endl;
	os << "Coins: " << (*chara.prizeMoney) << std::endl;
	return os;
}
