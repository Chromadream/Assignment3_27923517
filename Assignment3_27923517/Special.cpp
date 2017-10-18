#include "Special.h"

Special::Special(): Character()
{
	specialAtk = NULL;
}

Special::Special(std::string Name): Character(Name)
{
	specialAtk = NULL;
}

Special::Special(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk) :
	Character(Name, initialHealth, initialAtk, initialDef) {
	*specialAtk = SpecialAtk;
}

Special::~Special()
{
	delete specialAtk;
}

void Special::addSPAtk(int addition)
{
	*specialAtk += addition;
	if (this->getSPAtk() > 10)
	{
		*specialAtk = 10;
	}
}

void Special::resetSPAStatus()
{
	*specialAtkStatus = true;
}

bool Special::getSPAStatus()
{
	return *specialAtkStatus;
}

int Special::getSPAtk()
{
	return *specialAtk;
}

void Special::useSPAtk()
{
	*specialAtkStatus = false;
}
