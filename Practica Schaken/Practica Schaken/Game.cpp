/*
* Game.cpp
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Game.h"

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
		gameboard->printBoard();
		std::cout << "[" << ((activePlayer == WHITE) ? "WHITE" : "BLACK") << "] Please enter your move (e.g.: B4 B6 (element on B4 to B6)): ";
		char fromC, toC;
		int fromX, fromY, toX, toY;
		
		scanf("%c%i %c%i", &fromC, &fromY, &toC, &toY);
		flush_stdin();
		
		// Indexing on 0 but board has 1
		fromY--;
		toY--;

		fromX = (toupper(fromC) - 'A');
		toX = (toupper(toC) - 'A');
		
		// Check if origin exists
		if (fromX < 0 || fromX > 7 ||
			fromY < 0 || fromY > 7)
		{
			std::cout << "Invalid postion for source.";
			continue;
		}
		Piece* p = gameboard->getPieceAt(fromX, fromY);

		if (p == NULL)
		{
			std::cout << fromC << (fromY + 1) << " doesn't exist.";
			continue;
		}

		if (p->getColor() != activePlayer)
		{
			std::cout << "Illegal move, it's " << ((activePlayer == WHITE) ? "white's" : "black's") << " turn.";
			continue;
		}

		// Check if target exists
		if (toX < 0 || toX > 7 ||
			toY < 0 || toY > 7)
		{
			std::cout << "Invalid postion for target.";
			continue;
		}

		Move move(p, fromX, fromY, toX, toY);
		if (gameboard->move(p, move))
		{
			activePlayer = (activePlayer == WHITE) ? BLACK : WHITE;
		} else {
			std::cout << "Illegal move.";
		}
	}
}


Gameboard* Game::getGameboard()
{
	return gameboard;
}

/* Flush the stdin buffer (scanf leaves \n there)
   This way fgets on stdin doesn't just skip. */
void flush_stdin()
{
	char c;
	while ((c = (char) getchar()) != '\n' && c != EOF);
}

