#ifndef SPC_H
#define SPC_H
#include "Character.h"
class Special : public Character {
public:
	Special();
	Special(std::string Name);
	Special(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk);
	~Special();
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
