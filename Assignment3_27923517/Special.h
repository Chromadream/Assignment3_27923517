#ifndef SPC_H
#define SPC_H
#include "Character.h"
class Special : public Character {
public:
	Special(std::string Name);
	Special(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk);
	~Special();
	void addSPAtk(int addition);
	int getSPAtk();
protected:
	int* specialAtk;
};
#endif // !SPC_H
