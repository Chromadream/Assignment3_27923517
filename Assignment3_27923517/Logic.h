#ifndef LOGIC_H
#define LOGIC_H
#include "Character.h"
#include "Special.h"
#include "Hero.h"
#include "OtherFunc.h"
#include <iostream>
#include <random>
#include <vector>
class Logic {
public:
	Logic();
	void GameSetup();
	void GameStart();
private:
	std::vector<Character*> InvolvedCharacters;
	int HeroIndex;
	int currentEnemyIndex;
	int defeatedEnemyCounter;
	Hero* customizeHero();
	bool heroTurn();
	bool bossTurn();
	bool regularEnemyTurn();
	bool attack(Character* attacker, Character* defender);
	bool SpecialAtk(Special* attacker, Character* defender);
	int randGen(int lowerlimit, int upperlimit);
	void endBattle();
	void nextEnemy(void);
	void endGame(bool winStatus);
};
#endif //LOGIC_H