/*
* Game.cpp
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Game.h"
#include "Move.h"

void flush_stdin();

Game::Game()
{
	gameboard = new Gameboard(this);
	activePlayer = WHITE;
}
Game::~Game()
{
	delete gameboard;
}


void Game::startGame()
{
	bool running = true;
	while (running)
	{
		ui.displayBoard(*gameboard);
		ui.showActivePlayer(*this);
		enum UI::Command cmd = ui.askCommand(*this);
		if (cmd == UI::Command::MOVE) 
		{
			Move* move = ui.getLastMove();
			
			// Check if origin exists
			if (move->getFromX() < 0 || move->getFromX() > 7 ||
				move->getFromY() < 0 || move->getFromY() > 7)
			{
				std::cout << "Invalid postion for source.\n";
				continue;
			}

			Piece* p = move->getPiece();

			if (p == NULL)
			{
				std::cout << (char) ('A' + move->getFromX()) << (move->getFromY() + 1) << " doesn't exist.";
				continue;
			}

			if (p->getColor() != activePlayer)
			{
				std::cout << "Illegal move, it's " << ((activePlayer == WHITE) ? "white's" : "black's") << " turn.";
				continue;
			}

			// Check if target exists
			if (move->getToX() < 0 || move->getToX() > 7 ||
				move->getToY() < 0 || move->getToY() > 7)
			{
				std::cout << "Invalid postion for target.";
				continue;
			}

			if (gameboard->move(p, *move))
			{
				activePlayer = (activePlayer == WHITE) ? BLACK : WHITE;
			}
			else {
				std::cout << "Illegal move.";
			}
		}
			
	}
}


Gameboard* Game::getGameboard()
{
	return gameboard;
}

