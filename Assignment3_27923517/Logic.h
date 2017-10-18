#ifndef LOGIC_H
#define LOGIC_H
#include "Character.h"
#include "Special.h"
#include "Hero.h"
#include "OtherFunc.h"
#include <random>
#include <vector>
#include <algorithm>
#include <memory>

/*
 * Logic.h
 * Header file for the Logic class 
 */
class Logic {
public:
	Logic();
	void GameSetup();
	void GameStart();
	~Logic();
private:
	std::vector<Character*> InvolvedCharacters;
	int* HeroIndex;
	int* EnemyIndex;
	int* defeatedEnemyCounter;
	Hero* customizeHero();
	bool heroTurn();
	bool bossTurn();
	bool regularEnemyTurn();
	bool attack(Character* attacker, Character* defender);
	bool SpecialAtk(Special* attacker, Character* defender);
	void endBattle();
	void nextEnemy(void);
	void endGame(bool winStatus);
};
#endif //LOGIC_H