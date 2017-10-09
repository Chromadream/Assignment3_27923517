#ifndef CHAR_H
#define CHAR_H
#include <string>
class Character {
public:
	Character(std::string Name);
	Character(std::string Name, int initialHealth, int initialAtk, int initialDef);
	virtual ~Character();
	int getHealth();
	void setHealth(int newHealth);
	int getAtk();
	void addAtk(int addition);
	int getDef();
	void addDef(int addition);
protected:
	std::string* name;
	int* currHealth;
	int* attackPoint;
	int* defensePoint;
};

#endif // !HERO_H
