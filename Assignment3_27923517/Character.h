#ifndef CHAR_H
#define CHAR_H
#include <iostream>
#include <string>
class Character {
public:
	Character();
	Character(std::string Name);
	Character(std::string Name, int initialHealth, int initialAtk, int initialDef);
	virtual ~Character();
	std::string getName();
	int getHealth();
	void addHealth(int addition);
	bool decHealth(int subtraction);
	int getAtk();
	void addAtk(int addition);
	int getDef();
	void addDef(int addition);
	friend std::ostream& operator<<(std::ostream& os, const Character& chara);
protected:
	std::string* name;
	int* currHealth;
	int* attackPoint;
	int* defensePoint;
};

#endif // !HERO_H
