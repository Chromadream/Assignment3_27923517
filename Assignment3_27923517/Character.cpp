#include "Character.h"
/*
 * Character.cpp
 * Contains all functions specified in Character.h Headerfile.
 */

/*
 * Character()
 * Generic constructor, required for the vector
 */
Character::Character()
{
	name = NULL;
	currHealth = NULL;
	attackPoint = NULL;
	defensePoint = NULL;
}

/*
 * Character(std::string Name, int initialHealth, int initialAtk, int initialDef)
 * Overloaded constructor, also sets the Character's name and initial stats
 */
Character::Character(std::string Name, int initialHealth, int initialAtk, int initialDef)
{
	name = new std::string(Name);
	currHealth = new int(initialHealth);
	attackPoint = new int(initialAtk);
	defensePoint = new int(initialDef);
}

/*
 * ~Character()
 * Destructor for the Character class
 * deletes all the values referenced by the pointer variables
 */
Character::~Character()
{
	delete name;
	delete currHealth;
	delete attackPoint;
	delete defensePoint;
}

/*
 * Character::getName()
 * returns the name of the Character object
 */
std::string Character::getName()
{
	return *name;
}

/*
 * Character::getHealth()
 * returns the current health of the Character object
 */
int Character::getHealth()
{
	return *currHealth;
}

/*
 * Character::decHealth(int subtraction)
 * Decreases the Character's health according to the subtraction parameter
 * returns true if the Character's health reaches zero
 */

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

/*
 * Character::getAtk()
 * returns the attack point of the Character object
 */

int Character::getAtk()
{
	return *attackPoint;
}

/*
 * Character::addAtk(int addition)
 * adds the attack point of the Character object according to the addition parameter
 * limits the point to 10 points, if exceeded
 */
void Character::addAtk(int addition)
{
	*attackPoint += addition;
	if (this->getAtk() > 10)
	{
		*attackPoint = 10;
	}
}

/*
 * Character::getDef()
 * returns the defense point of the Character object
 */

int Character::getDef()
{
	return *defensePoint;
}

/*
 * Character::addDef(int addition)
 * adds the defense point of the Character object according to the addition parameter
 * limits the point to 10 points, if exceeded
 */
void Character::addDef(int addition)
{
	*defensePoint += addition;
	if (this->getDef() > 10)
	{
		*defensePoint = 10;
	}
}

/*
 * operator<<(std::ostream & os, const Character & chara)
 * Overloads the << operator, so that it will show the Character's name, health points, and health bar
 */

std::ostream & operator<<(std::ostream & os, const Character & chara)
{
	double charaHealth = ceil((double)(*chara.currHealth)/10);
	double healthRem = 10 - charaHealth;
	os << *chara.name << std::endl;
	os << std::string(12, '-') << std::endl;
	os << "|" << std::string(charaHealth, '*')<<std::string(healthRem,' ')<<"|" << std::endl;
	os << std::string(12, '-') << std::endl;
	os << "Health: " << (*chara.currHealth) << "/100" << std::endl;
	return os;
}
