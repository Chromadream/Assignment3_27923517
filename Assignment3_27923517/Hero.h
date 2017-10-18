#ifndef HERO_H
#define HERO_H
#include "Special.h"
class Hero : public Special {
public:
	Hero();
	Hero(std::string Name);
	Hero(std::string Name, int initialHealth, int initialAtk, int initialDef, int SpecialAtk);
	~Hero();
	void addHealth(int addition);
	void addPrizeMoney(int money);
	int returnPrizeMoney();
	friend std::ostream& operator<<(std::ostream& os, const Hero& chara);
private:
	int* prizeMoney;
};
#endif //HERO_H