#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Spel.h"

void flush_stdin();

Spel::Spel()
{
	spelbord = new Spelbord(this);
	activePlayer = WHITE;
}
Spel::~Spel()
{
	delete spelbord;
}


void Spel::startSpel()
{
	while (true)
	{
		spelbord->printBoard();
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
		Pion* p = spelbord->board[fromY][fromX];

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

		if (spelbord->move(p, fromX, fromY, toX, toY))
		{
			activePlayer = (activePlayer == WHITE) ? BLACK : WHITE;
		} else {
			std::cout << "Illegal move.";
		}
	}
}

bool Spel::isValidMove(Pion &pion, int fromX, int fromY, int toX, int toY)
{
	int i, j;
	bool isValid = true;
	if (activePlayer == WHITE)
	{
		switch (pion.getType())
		{
		case Pion::SOLDIER:
			for (j = fromY; j >= toY; j--)
				if (spelbord->board[j][fromX] != NULL)
					isValid = false;
			return isValid;

		case Pion::HORSE:
			if (spelbord->board[toY][toX]->getColor() == WHITE)
				isValid = false;
			return isValid;
			//de rest komt nog
		}
	}
}

Spelbord* Spel::getSpelbord()
{
	return spelbord;
}

/* Flush the stdin buffer (scanf leaves \n there)
   This way fgets on stdin doesn't just skip. */
void flush_stdin()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

