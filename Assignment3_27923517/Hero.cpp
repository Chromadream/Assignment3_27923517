#include "Hero.h"
/*
 * Hero.cpp
 * Contains all functions specified in Hero.h Headerfile.
 */

/*
 * Hero(std::string Name)
 * Constructor for the Hero object, in the case where the Hero is not customized
 */
Hero::Hero(std::string Name):
	Special(Name,20,3,3,2)
{
	prizeMoney = new int(0);//initialize the prize money
}

/*
 * Hero(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk)
 * Constructor for the Hero object, in the case where the Hero is customized by the player
 */
Hero::Hero(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk): 
	Special(Name, initialHealth, initialAtk, initialDef, SpecialAtk)
{
	prizeMoney = new int(0);//initialize the prize money
}

/*
 * ~Hero()
 * Destructor for Hero class
 * deletes value pointed by the pointer on the Hero class
 */
Hero::~Hero()
{
	delete prizeMoney;
}

/*
 * Hero::addHealth()
 * Adds 20HP for each successful battle to the Hero object
 * limits the HP to 50, if exceeded
 */
void Hero::addHealth()
{
	*currHealth += 20;
	if (this->getHealth() > 50)
	{
		*currHealth = 50;
	}
}

/*
 * Hero::addPrizeMoney(int money)
 * Adds the prize money to the private variable according to the input parameter
 */
void Hero::addPrizeMoney(int money)
{
	*prizeMoney += money;
}

/*
 * Hero::returnPrizeMoney()
 * returns the earned prize money of the Hero object
 */
int Hero::returnPrizeMoney()
{
	return *prizeMoney;
}

/*
 * operator<<(std::ostream & os, const Hero & chara)
 * Overloads the << operator so that it shows Hero name, Health bar, and comprehensive stats of the Hero
 */
std::ostream & operator<<(std::ostream & os, const Hero & chara)
{
	double charaHealth = ceil((double)(*chara.currHealth) / 10);
	double healthRem = 10 - charaHealth;
	os << "Hero name: " << (*chara.name) << std::endl;
	os << std::string(12, '-') << std::endl;
	os << "|" << std::string(charaHealth, '*') << std::string(healthRem, ' ') << "|" << std::endl;
	os << std::string(12, '-') << std::endl;
	os << "Health: " << (*chara.currHealth) << "/50" << std::endl;
	os << "Attack: " << (*chara.attackPoint) << std::endl;
	os << "Defense: " << (*chara.defensePoint) << std::endl;
	os << "Special: " << (*chara.specialAtk) << std::endl;
	os << "Coins: " << (*chara.prizeMoney) << std::endl;
	return os;
}
