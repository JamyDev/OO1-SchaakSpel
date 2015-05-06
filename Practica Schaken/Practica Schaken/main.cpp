/*
* main.cpp
* Authors: Jamy Timmermans
*/

#include <iostream>
#include <conio.h>
#include "game.h"


int main(void)
{
	std::cout << "Chess by Jamy and Jeroen" << "\n" <<
		"Shall we play a game?";
	//_getche();
	Game* game = new Game();
	game->startGame();
	game->getGameboard()->printBoard();

	delete game;
	return 0;

}