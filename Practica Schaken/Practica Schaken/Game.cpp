/*
* Game.cpp
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Game.h"
#include "Move.h"
#include "FileIO.h"

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
				ui.showError("Invalid postion for source.");
				continue;
			}

			Piece* p = move->getPiece();

			char error[30];

			if (p == NULL)
			{
				strcpy(error, "__ doesn't exist.");
				error[0] = (char)('A' + move->getFromX());
				error[1] = (move->getFromY() + 1);
				ui.showError(error);
				continue;
			}

			if (p->getColor() != activePlayer)
			{
				strcpy(error, "Illegal move, this is not your piece.");
			
				ui.showError(error);
				continue;
			}

			// Check if target exists
			if (move->getToX() < 0 || move->getToX() > 7 ||
				move->getToY() < 0 || move->getToY() > 7)
			{
				ui.showError("Invalid postion for target.");
				continue;
			}

			if (gameboard->move(p, *move))
			{
				activePlayer = (activePlayer == WHITE) ? BLACK : WHITE;
			}
			else {
				ui.showError("Illegal move.");
			}
		}
		else if (cmd == UI::Command::HELP) 
		{
			ui.showHelp();
		}
		else if (cmd == UI::Command::QUIT)
		{
			running = false;
		}
		else if (cmd == UI::Command::LOAD)
		{
			activePlayer = (Game::PlayerColor) FileIO::getActivePlayer();
			gameboard->clearBoard();
			FileIO::getBoardFromFile(gameboard);
		}
		else if (cmd == UI::Command::SAVE)
		{
			FileIO::putToFile(*this);
		}
	}
}


Gameboard* Game::getGameboard()
{
	return gameboard;
}

