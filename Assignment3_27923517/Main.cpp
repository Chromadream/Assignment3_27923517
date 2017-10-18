#include "Logic.h"
#include <time.h>

/*
 * int main(void)
 * 
 * Main execution file
 * Initiates a Logic instance, and starts the game.
 */
int main(void)
{
	srand(time(NULL));//initiates random seeding
	Logic* Game = new Logic();//initialize a Logic instance
	Game->GameSetup();//executes initial setup of the game
	system("cls");//clears the screen
	Game->GameStart();//starts the game
	system("pause");//pauses the console
	delete Game;//removes the Logic instance used
	return 0;
}