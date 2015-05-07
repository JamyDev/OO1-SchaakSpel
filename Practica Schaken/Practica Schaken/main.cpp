/*
* main.cpp
* Authors: Jamy Timmermans
*/

#include <iostream>
#include <conio.h>
#include "game.h"


int main(void)
{
	Game* game = new Game();
	game->startGame();

	delete game;
	return 0;

}