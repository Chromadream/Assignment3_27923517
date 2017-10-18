#ifndef HERO_H
#define HERO_H
#include "Special.h"
/*
 * Hero.h
 * Header file for the Hero class
 * Inherited from Special class, which is inherited from the Character class
 */
class Hero : public Special {
public:
	Hero(std::string Name);
	Hero(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk);
	virtual ~Hero();
	void addHealth();
	void addPrizeMoney(int money);
	int returnPrizeMoney();
	friend std::ostream& operator<<(std::ostream& os, const Hero& chara);
private:
	int* prizeMoney;
};
#endif //HERO_H