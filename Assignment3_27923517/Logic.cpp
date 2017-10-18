#include "Logic.h"

Logic::Logic()
{
	HeroIndex = NULL;
	currentEnemyIndex = NULL;
	defeatedEnemyCounter = NULL;
}

void Logic::GameSetup()
{
	char input;
	std::cout << "Hello adventurer. \nBefore we begin, do you like to create your own hero? (Y/N) ";
	std::cin >> input;
	if (input == 'Y' || input == 'y')
	{
		Hero* hero = customizeHero();
		InvolvedCharacters.push_back(hero);
	}
	else
	{
		std::string name;
		std::cout << "Please enter the hero's name: ";
		std::cin >> name;
		Hero* hero = new Hero(name);
		InvolvedCharacters.push_back(hero);
	}
	InvolvedCharacters.push_back(new Character("Huang Long", 10, 1, 1));
	InvolvedCharacters.push_back(new Character("Koga Saburo", 20, 3, 2));
	InvolvedCharacters.push_back(new Character("Onmoraki", 30, 5, 4));
	InvolvedCharacters.push_back(new Character("Fenrir", 40, 6, 7));
	InvolvedCharacters.push_back(new Special("Take-Mikazuchi", 50, 8, 8, 6));
	HeroIndex = 0;
	currentEnemyIndex = 1;
	defeatedEnemyCounter = 0;
}

void Logic::GameStart()
{
	bool winStatus, died = false, diedEnemy;
	std::cout << "Your first enemy appears. " << InvolvedCharacters[currentEnemyIndex]->getName() << std::endl;
	while (defeatedEnemyCounter < 5 || died == false)
	{
		diedEnemy = heroTurn();
		if (diedEnemy&&defeatedEnemyCounter!=5)
		{
			nextEnemy();
		}
		else if (diedEnemy&&defeatedEnemyCounter == 5)
		{
			winStatus = true;
			endGame(winStatus);
		}
        if (defeatedEnemyCounter == 4)
        {
            died = bossTurn();
        }
        else
        {
            died = regularEnemyTurn();
        }
		if (died)
		{
			winStatus = false;
			endGame(winStatus);
			break;
		}
	}
}

Hero* Logic::customizeHero()
{
	std::string name;
	int initCharPoints = 8;
	int attack, defense, health = 20, specialatk;
	std::cout << "Please enter the hero's name: ";
	std::cin >> name;
	std::cout << "You have " << initCharPoints << "points usable for initial character customization" << std::endl;
	std::cout << "Points unused will be lost forever in darkness :)" << std::endl;
	std::cout << "Enter desired initial attack points: ";
	attack = IntegerCheck(initCharPoints, 0);
	initCharPoints -= attack;
	std::cout << "You have " << initCharPoints << "points left for initial character customization" << std::endl;
	std::cout << "Enter desired initial defense points: ";
	defense = IntegerCheck(initCharPoints, 0);
	std::cout << "Generating random special attack points."<<std::endl;
	specialatk = randGen(0, 10);
	return new Hero(name, health, attack, defense, specialatk);
}

bool Logic::heroTurn()
{
	char specialAtk;
	bool win = false;
	Hero* temp = static_cast<Hero*>(InvolvedCharacters[HeroIndex]);
	std::cout << *temp << std::endl;
	if (temp->getSPAStatus())
	{
		std::cout << "Do you want to use the special attack? (Y/N) ";
		std::cin >> specialAtk;
		if (specialAtk == 'y' || specialAtk == 'Y')
		{
			win = SpecialAtk(temp, InvolvedCharacters[currentEnemyIndex]);
		}
		else
		{
			win = attack(temp, InvolvedCharacters[currentEnemyIndex]);
		}
	}
	else
	{
		win = attack(temp, InvolvedCharacters[currentEnemyIndex]);
	}
	return win;
}

bool Logic::bossTurn()
{
	bool win = false;
	Special* temp = static_cast<Special*>(InvolvedCharacters[currentEnemyIndex]);
	std::cout << *temp << std::endl;
	if (randGen(0, 10) > 5 && temp->getSPAStatus())
	{
		win = SpecialAtk(temp, InvolvedCharacters[HeroIndex]);
	}
	else
	{
		win = attack(temp, InvolvedCharacters[HeroIndex]);
	}
	return win;
}

bool Logic::regularEnemyTurn()
{
	bool win = false;
	std::cout << *InvolvedCharacters[currentEnemyIndex] << std::endl;
	win = attack(InvolvedCharacters[currentEnemyIndex], InvolvedCharacters[HeroIndex]);
	return win;
}

bool Logic::attack(Character * attacker, Character * defender)
{
	bool dead = false;
	int dmg = (attacker->getAtk() + randGen(1, 6)) - (defender->getDef() + randGen(1, 6));
	if (dmg > 0)
	{

		dead = defender->decHealth(dmg);
	}
	else
	{
		dmg = 0;
	}
	std::cout << attacker->getName() << " dealt " << dmg << " damages." << std::endl;
	return dead;
}

bool Logic::SpecialAtk(Special * attacker, Character * defender)
{
	bool dead = false;
	int atkpt = attacker->getAtk() + attacker->getSPAtk() + randGen(1, 6);
	attacker->useSPAtk();
	int dmg = atkpt - (defender->getDef() + randGen(1, 6));
	if (dmg > 0)
	{

		dead = defender->decHealth(dmg);
	}
	else
	{
		dmg = 0;
	}
	std::cout << attacker->getName() << " dealt " << dmg << " damages." << std::endl;
	return dead;
}

int Logic::randGen(int lowerlimit, int upperlimit)
{
	return rand() % upperlimit + lowerlimit;
}

void Logic::endBattle()
{
	Hero* temp = static_cast<Hero*>(InvolvedCharacters[HeroIndex]);
	temp->addPrizeMoney(temp->getHealth());
	temp->addHealth(20);
	temp->addAtk(randGen(0, 2));
	temp->addDef(randGen(0, 2));
	temp->addSPAtk(randGen(0, 2));
	temp->resetSPAStatus();
}

void Logic::nextEnemy(void)
{
	endBattle();
	std::cout << "Defeated " << InvolvedCharacters[currentEnemyIndex]->getName() << std::endl;
	InvolvedCharacters.erase(InvolvedCharacters.begin()+1);
	(defeatedEnemyCounter)++;
	system("pause");
	system("cls");
	std::cout << "A new enemy appears! " << InvolvedCharacters[currentEnemyIndex]->getName() << std::endl;
}

void Logic::endGame(bool winStatus)
{
	if (winStatus)
	{
		std::cout << "You persevered and won." << std::endl;
	}
	else
	{
		std::cout << "You died." << std::endl;
	}
	std::cout << "Destroyed " << defeatedEnemyCounter << " enemies." << std::endl;
	std::cout << "Obtained " << static_cast<Hero*>(InvolvedCharacters[HeroIndex])->returnPrizeMoney() << " golds." << std::endl;
	std::cout << "Thank you for playing!" << std::endl;
}

