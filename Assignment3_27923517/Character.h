#ifndef CHAR_H
#define CHAR_H
#include <iostream>
#include <string>

/*
 * Character.h
 * Header file for the Character class
 * Serves as the class used by regular enemies, and base for Special class
 */

class Character {
public:
	Character();
	Character(std::string Name, int initialHealth, int initialAtk, int initialDef);
	virtual ~Character();
	std::string getName();
	int getHealth();
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
