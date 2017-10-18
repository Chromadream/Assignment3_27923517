#ifndef SPC_H
#define SPC_H
#include "Character.h"

/*
 * Special.h
 * Header file for the Special class
 * Inherited from Character class
 * Serves as base class for Hero class
 */
class Special : public Character {
public:
	Special(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk);
	virtual ~Special();
	void addSPAtk(int addition);
	void resetSPAStatus();
	bool getSPAStatus();
	int getSPAtk();
	void useSPAtk();
protected:
	bool* specialAtkStatus;
	int* specialAtk;
};
#endif // !SPC_H
