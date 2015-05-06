#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Game.h"


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
	while (true)
	{
		gameboard->printBoard();
		std::cout << "[" << ((activePlayer == WHITE) ? "WHITE" : "BLACK") << "] Please enter your move (e.g.: B4 B6 (element on B4 to B6)): ";
		char fromC, toC;
		int fromX, fromY, toX, toY;
		
		scanf("%c%i %c%i", &fromC, &fromX, &toC, &toX);
		
		// Indexing on 0 but board has 1
		fromX--;
		toX--;

		fromY = (toupper(fromC) - 'A');
		toY = (toupper(toC) - 'A');
		
		// Check if origin exists
		if (fromX < 0 || fromX > 7 ||
			fromY < 0 || fromY > 7)
		{
			std::cout << "Invalid postion for source.";
			continue;
		}
		Piece* p = gameboard->board[fromY][fromX];

		if (p == NULL)
		{
			std::cout << fromC << fromX << " doesn't exist.";
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

		if (gameboard->move(p, fromX, fromY, toX, toY))
		{
			activePlayer = (activePlayer == WHITE) ? BLACK : WHITE;
		} else {
			std::cout << "Illegal move.";
		}
	}
}

bool Game::isValidMove(Piece &piece, int fromX, int fromY, int toX, int toY)
{
	int i, j;
	bool isValid = true;
	if (activePlayer == WHITE)
	{
		switch (piece.getType())
		{
		case Piece::SOLDIER:
			for (j = fromY; j >= toY; j--)
				if (gameboard->board[j][fromX] != NULL)
					isValid = false;
			return isValid;

		case Piece::HORSE:
			if (gameboard->board[toY][toX]->getColor() == WHITE)
				isValid = false;
			return isValid;
			//de rest komt nog
		}
	}
}

Gameboard* Game::getGameboard()
{
	return gameboard;
}
