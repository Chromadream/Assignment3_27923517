#include "Special.h"
/*
 * Special.cpp
 * Contains all functions specified in Special.h Headerfile.
 */

/*
 * Special(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk)
 * Constructor for Special class, which will call the overloaded constructor for Character class
 * Also sets the Special Attack stats
 */
Special::Special(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk) :
	Character(Name, initialHealth, initialAtk, initialDef) {
	specialAtk = new int(SpecialAtk);
	specialAtkStatus = new bool(true);
}

/*
 * ~Special()
 * Destructor for Special class
 * deletes value pointed by the pointer on the Special class
 */
Special::~Special()
{
	delete specialAtk;
}

/*
 * Special::addSPAtk(int addition)
 * adds the Special Attack point of the Special object according to the addition parameter
 * limits the point to 10 points, if exceeded
 */
void Special::addSPAtk(int addition)
{
	*specialAtk += addition;
	if (this->getSPAtk() > 10)
	{
		*specialAtk = 10;
	}
}

/*
 * Special::resetSPAStatus()
 * Resets the status of the Special Attack, so that it can be used after each battle
 */
void Special::resetSPAStatus()
{
	*specialAtkStatus = true;
}

/*
 * Special::getSPAStatus()
 * returns the status of the Special Attack, whether it is used already or not
 */
bool Special::getSPAStatus()
{
	return *specialAtkStatus;
}

/*
 * Special::getSPAtk()
 * returns the Special Attack point of the Special object
 */
int Special::getSPAtk()
{
	return *specialAtk;
}

/*
 * Special::useSPAtk()
 * sets the Special Attack status so that it can't be used until it is reset
 */
void Special::useSPAtk()
{
	*specialAtkStatus = false;
}
