#include "Logic.h"
/*
 * Logic.cpp
 * Contains all functions specified in Logic.h Headerfile.
 */

/*
 * Logic()
 * Default constructor of the Logic instance
 */
Logic::Logic()
{
	HeroIndex = NULL;
	EnemyIndex = NULL;
	defeatedEnemyCounter = NULL;
}

/*
 * Logic::GameSetup()
 * Public function that initiates the game, sets the Hero stats, and adds the enemies
 */
void Logic::GameSetup()
{
	//variable initialization
	std::string input;
	bool validity = false;
	//welcome text
	std::cout << "Hello adventurer, and welcome to Hero's Quest." << std::endl;
	std::cout<<"Before we begin, do you like to create your own hero ? (Y / N) ";
	std::cin >> input;
	while (!validity)
	{
		if (input == "Y" || input == "y")
		{
			//If the player wants to customize his hero
			InvolvedCharacters.push_back(customizeHero());
			validity = true;
		}
		else if (input == "N" || input == "n")
		{
			//If the player just want to use the pre-defined hero
			std::string name;
			std::cout << "Please enter the hero's name: ";
			std::cin.ignore();//clears the cin \n character
			std::getline(std::cin, name);//gets the player name
			InvolvedCharacters.push_back(new Hero(name));//initiates new Hero instance, and push it to the vector
			validity = true;
		}
		else
		{
			std::cout << "Input is invalid! (Y/N)";
			std::cin >> input;
		}
	}
	//initiates enemies to the vector
	InvolvedCharacters.push_back(new Character("Izanagi", 10, 1, 1));
	InvolvedCharacters.push_back(new Character("Kintoku-Douji", 20, 3, 2));
	InvolvedCharacters.push_back(new Character("Seiten Taisen", 30, 5, 4));
	InvolvedCharacters.push_back(new Character("Magatsu-Izanagi", 40, 6, 7));
	InvolvedCharacters.push_back(new Special("Izanagi-no-Okami", 50, 8, 8, 6));//Boss character
	//initiates the index position of the hero and the enemy on the vector
	HeroIndex = new int(0);
	EnemyIndex = new int(1);
	defeatedEnemyCounter = new int(0);//initiates the defeated enemy counter
}

/*
 * Logic::GameStart()
 * A running instance of the game, with control on which Character takes turn
 */

void Logic::GameStart()
{
	//boolean definition
	bool winStatus, died = false, diedEnemy;
	std::cout << "Your first enemy appears. " << InvolvedCharacters[*EnemyIndex]->getName() << std::endl;
	while (*defeatedEnemyCounter < 5 && died == false)
	{
		diedEnemy = heroTurn();//Hero's turn
		if (diedEnemy)
		{
			(*defeatedEnemyCounter)++;//adding dead enemies counter
		}
		if ((*defeatedEnemyCounter) == 5)
		{
			//All enemies are cleared, including the boss
			endBattle();
			winStatus = true;
			endGame(winStatus);
		}
		else if (diedEnemy&&(*defeatedEnemyCounter) == 4)
		{
			//if the current enemy is dead, and the next enemy is the boss.
			nextEnemy();
			std::cout << "WARNING! The boss " << InvolvedCharacters[*EnemyIndex]->getName() << " appears!" << std::endl;
			std::cout << "Good luck!" << std::endl;
		}
		else if (diedEnemy&&(*defeatedEnemyCounter)<4)
		{
			//If the enemy is died, and not all regular enemy is dead.
			nextEnemy();
			std::cout << "A new enemy appears! " << InvolvedCharacters[*EnemyIndex]->getName() << std::endl;
		}
        if (InvolvedCharacters.size()==2)
        {
			//Boss' turn
            died = bossTurn();
        }
        else
        {
			//regular player turn
            died = regularEnemyTurn();
        }
		if (died)
		{
			//If player died from the battle
			system("pause");
			winStatus = false;
			endGame(winStatus);
		}
	}
}

/*
 * Logic::~Logic()
 * Destructor for the Logic class
 */

Logic::~Logic()
{
	delete HeroIndex;
	delete EnemyIndex;
	delete defeatedEnemyCounter;
	std::for_each(InvolvedCharacters.begin(), InvolvedCharacters.end(), std::default_delete<Character>());
}

/*
 * Logic::customizeHero()
 * Function used if the player decided to create their own hero
 * 10 points is to be allocated between attack and defense points
 * Special attack is randomly generated between 0-10 points
 * Initial health point still retains the same as the specification
 */

Hero* Logic::customizeHero()
{
	//variable initialization
	std::string name;
	int initCharPoints = 10;
	int attack, defense, health = 20, specialatk;
	std::cout << "Please enter the hero's name: ";
	std::cin.ignore();//clearing \n from previous user input
	std::getline(std::cin, name);//hero name input
	std::cout << "You have " << initCharPoints << " points usable for initial character customization" << std::endl;
	std::cout << "Points unused will be lost forever in darkness :)" << std::endl;
	std::cout << "Enter desired initial attack points: ";
	attack = IntegerCheck(initCharPoints, 0);
	initCharPoints -= attack;//reducing the remaining character development point from the attack
	std::cout << "You have " << initCharPoints << " points left for initial character customization" << std::endl;
	std::cout << "Enter desired initial defense points: ";
	defense = IntegerCheck(initCharPoints, 0);
	std::cout << "Generating random special attack points."<<std::endl;
	specialatk = randGen(0, 10);//random generation of Special Attack points
	return new Hero(name, health, attack, defense, specialatk);//returning the newly built hero class
}

/*
 * Logic::heroTurn()
 * A chain of commands that is used when it is the hero's turn
 * Includes user input process, but otherwise the same as bossTurn(), as both boss and hero can use special attack
 */
bool Logic::heroTurn()
{
	//variable initialization
	std::string specialAtk;
	bool win = false;
	Hero* temp = static_cast<Hero*>(InvolvedCharacters[*HeroIndex]);//Polymorphism static_cast to the Hero class
	std::cout << *temp << std::endl;//Printing the hero class stats
	if (temp->getSPAStatus())
	{
		//the case where special attack is unused
		std::cout << "Do you want to use the special attack? (Y/N) ";
		std::cin >> specialAtk;
		if (specialAtk == "Y" || specialAtk == "y")
		{
			win = SpecialAtk(temp, InvolvedCharacters[*EnemyIndex]);
		}
		else
		{
			//it is assumed that all input other than Y/y implies that the player don't want to use the special attack
			win = attack(temp, InvolvedCharacters[*EnemyIndex]);
		}
	}
	else
	{
		//the case where special attack is already used by the player
		win = attack(temp, InvolvedCharacters[*EnemyIndex]);
	}
	return win;
}

/*
 * Logic::bossTurn()
 * Used by boss on each turn
 * Will use special attack randomly, if still available
 * 
 */
bool Logic::bossTurn()
{
	//variable initialization
	bool win = false;
	Special* temp = static_cast<Special*>(InvolvedCharacters[*EnemyIndex]);//Polymorphism static_cast to the Special class
	std::cout << *temp << std::endl;//prints the boss' HP bar
	if (randGen(0, 10) > 5 && temp->getSPAStatus())
	{
		//the case where special attack is used
		win = SpecialAtk(temp, InvolvedCharacters[*HeroIndex]);
	}
	else
	{
		//the case where special attack is not used, or already used
		win = attack(temp, InvolvedCharacters[*HeroIndex]);
	}
	return win;
}

/*
 * Logic::regularEnemyTurn()
 * Used by regular enemy, which will attack directly
 */
bool Logic::regularEnemyTurn()
{
	//variable initialization
	bool win = false;
	std::cout << *InvolvedCharacters[*EnemyIndex] << std::endl;//prints the enemy's HP bar
	win = attack(InvolvedCharacters[*EnemyIndex], InvolvedCharacters[*HeroIndex]);
	return win;
}

/*
 * Logic::attack(Character* attacker, Character* defender)
 * Do an attack, if attacker's attack point + random number is higher than defender's defense point + random number
 */
bool Logic::attack(Character * attacker, Character * defender)
{
	bool dead = false;
	int dmg = (attacker->getAtk() + randGen(1, 6)) - (defender->getDef() + randGen(1, 6));//damage calculation
	if (dmg > 0)
	{
		//if the attack point is higher than the defense point, with the random extra number
		dead = defender->decHealth(dmg);
	}
	else
	{
		//sets the damage dealt as zero
		dmg = 0;
	}
	std::cout << attacker->getName() << " dealt " << dmg << " damages." << std::endl;//prints the damage dealt
	return dead;
}
/*
 * Logic::attack(Special* attacker, Character* defender)
 * Do a special attack, if attacker's attack point + random number is higher than defender's defense point + random number
 */
bool Logic::SpecialAtk(Special * attacker, Character * defender)
{
	std::cout << "Special attack is used, beware!" << std::endl;
	bool dead = false;
	int atkpt = attacker->getAtk() + attacker->getSPAtk() + randGen(1, 6);
	attacker->useSPAtk();//sets special attack, so that it is unusable for the rest of the battle
	int dmg = atkpt - (defender->getDef() + randGen(1, 6));
	if (dmg > 0)
	{
		//if the attack point is higher than the defense point, with the random extra number
		dead = defender->decHealth(dmg);
	}
	else
	{
		//sets the damage dealt as zero
		dmg = 0;
	}
	std::cout << attacker->getName() << " dealt " << dmg << " damages." << std::endl;//prints the damage dealt
	return dead;
}

/*
 * Logic::endBattle()
 * Each of the end battle, the hero will receive prize money, and addition on health
 * There is also random addition on the hero's stats
 */
void Logic::endBattle()
{
	Hero* temp = static_cast<Hero*>(InvolvedCharacters[*HeroIndex]);
	temp->addPrizeMoney(temp->getHealth());//add prize money according to the health left
	temp->addHealth();//adds 20 HP each battle
	//random addition on the hero's stats, ranged from 0-2pts
	temp->addAtk(randGen(0, 2));
	temp->addDef(randGen(0, 2));
	temp->addSPAtk(randGen(0, 2));
	temp->resetSPAStatus();//resets the Special Attack usage
}

/*
 * Logic::nextEnemy()
 * Removes the dead enemy, so that the next enemy's position is at index 1 on the vector
 * Also calls the endBattle() function
 */
void Logic::nextEnemy()
{
	endBattle();
	std::cout << "Defeated " << InvolvedCharacters[*EnemyIndex]->getName() << std::endl;
	delete InvolvedCharacters[*EnemyIndex];//deletes the enemy object on the Vector
	InvolvedCharacters[*EnemyIndex] = NULL;//points the pointer to NULL
	InvolvedCharacters.erase(InvolvedCharacters.begin()+1);//erases the pointer from the vector
	system("pause");//pauses the console print
	system("cls");//clears the screen
}

/*
 * Logic::endGame(bool winStatus)
 * Shows the endgame credits, according to the condition whether the player clears the game or not
 */
void Logic::endGame(bool winStatus)
{
	system("cls");
	if (winStatus)
	{
		//the case where the player wins the game
		endBattle();//calls the endBattle function
		std::cout << "Against all odds, you won!" << std::endl;
	}
	else
	{
		//the case where the player loses the game
		std::cout << "You died." << std::endl;
	}
	//prints the defeated enemy counter and prize money obtained
	std::cout << "Killed " << *defeatedEnemyCounter << " enemies." << std::endl;
	std::cout << "Obtained " << static_cast<Hero*>(InvolvedCharacters[*HeroIndex])->returnPrizeMoney() << " golds." << std::endl;
	std::cout << "Thank you for playing!" << std::endl;
}

