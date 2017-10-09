#ifndef HERO_H
#define HERO_H
#include "Special.h"
class Hero : public Special {
public:
	Hero(std::string Name);
	~Hero();
	void setHealth(int newHealth);
	void addPrizeMoney();
	int returnPrizeMoney();
private:
	int* prizeMoney;
};
#endif //HERO_H