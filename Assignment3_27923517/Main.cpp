#include "Logic.h"

int main(void)
{
	Logic Game;
	Game = Logic();
	Game.GameSetup();
	Game.GameStart();
	system("pause");
	return 0;
}