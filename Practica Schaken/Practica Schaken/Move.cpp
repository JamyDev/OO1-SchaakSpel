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

bool Move::canKingMove(int fromX, int fromY, int toX, int toY)
{
	if (toX < 0 || toY < 0 || toX >= VELDGROOTTE || toY >= VELDGROOTTE)
		return false;
	if (fromX == toX && fromY == toY)
		return false;
	if (fromX - 1 == toX || fromY - 1 == toY || fromX + 1 == toX || fromY + 1 == toY)
		return true;
	else
		return false;
}

int Move::getToX() const
{
	return newX;
}

int Move::getToY() const
{
	return newY;
}