#include <stdlib.h>
#include "Spel.h"


Spel::Spel()
{
	spelbord = new Spelbord;
	activePlayer = WHITE;
}
Spel::~Spel()
{
	delete spelbord;
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
				if (spelbord->board[fromX][j] != NULL)
					isValid = false;
			return isValid;

		case Pion::HORSE:
			if (spelbord->board[toX][toY]->getType() == WHITE)
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
