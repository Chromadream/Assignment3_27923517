#include "Logic.h"

int main(void)
{
	Logic Game;
	Game = Logic();
	Game.GameSetup();
	system("cls");
	Game.GameStart();
	system("pause");
	return 0;
}