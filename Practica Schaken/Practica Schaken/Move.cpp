/*
* Move.cpp
* Authors: Jeroen Ceyssens
*/

#include <stdlib.h>
#include "Move.h"
#include "Gameboard.h"

Move::Move()
{
	piece = NULL;
	originalX = 0;
	originalY = 0;
	newX = 0;
	newY = 0;
}

Move::Move(Piece* usedPion, int fromX, int fromY, int toX, int toY)
{
	piece = usedPion;
	originalX = fromX;
	originalY = fromY;
	newX = toX;
	newY = toY;
}

int Move::getToX() const
{
	return newX;
}

int Move::getToY() const
{
	return newY;
}