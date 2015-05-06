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

bool Move::canHorseMove(int fromX, int fromY, int toX, int toY)
{
	if (toX < 0 || toY < 0 || toX >= VELDGROOTTE || toY >= VELDGROOTTE)
		return false;
	if (fromX - 2 == toX && (fromY - 1 == toY || fromY + 1 == toY))
		return true;
	else if (fromX + 2 == toX && (fromY - 1 == toY || fromY + 1 == toY))
		return true;
	else if (fromY - 2 == toY && (fromX - 1 == toX || fromX + 1 == toX))
		return true;
	else if (fromY + 2 == toY && (fromX - 1 == toX || fromX + 1 == toX))
		return true;
	else
		return false;
}

bool Move::canSoldMove(int fromX, int fromY, int toX, int toY, bool isFirst, enum Piece::Color color)
{
	if (toX < 0 || toY < 0 || toX >= VELDGROOTTE || toY >= VELDGROOTTE)
		return false;
	if (color == Piece::BLACK)
	{
		if (fromX == toX && fromY - 1 == toY)
			return true;
		else if (fromX == toX && fromY - 2 == toY && isFirst == true)
			return true;
		else
			return false;
	}
	else if (color == Piece::WHITE)
	{
		if (fromX == toX && fromY + 1 == toY)
			return true;
		else if (fromX == toX && fromY + 2 == toY && isFirst == true)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Move::canSoldAttack(int fromX, int fromY, int toX, int toY, enum Piece::Color color)
{
	if (toX < 0 || toY < 0 || toX >= VELDGROOTTE || toY >= VELDGROOTTE)
		return false;
	if (color == Piece::BLACK)
	{
		if (fromX - 1 == toX && fromY - 1 == toY)
			return true;
		else if (fromX + 1 == toX && fromY - 1 == toY)
			return true;
		else
			return false;
	}
	else if (color == Piece::WHITE)
	{
		if (fromX - 1 == toX && fromY + 1 == toY)
			return true;
		else if (fromX + 1 == toX && fromY + 1 == toY)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Move::canCastleMove(int fromX, int fromY, int toX, int toY)
{
	if (toX < 0 || toY < 0 || toX >= VELDGROOTTE || toY >= VELDGROOTTE)
		return false;
	if (fromX == toX && fromY == toY)
		return false;
	if (fromX == toX || fromY == toY)
		return true;
	else
		return false;
}

bool Move::canBissMove(int fromX, int fromY, int toX, int toY)
{
	if (toX < 0 || toY < 0 || toX >= VELDGROOTTE || toY >= VELDGROOTTE)
		return false;
	if (fromX == toX && fromY == toY)
		return false;
	if (toX - fromX == toY - fromY || toX - fromX == -(toY - fromY))
		return true;
	else
		return false;
}

bool Move::canQueenMove(int fromX, int fromY, int toX, int toY)
{
	if (toX < 0 || toY < 0 || toX >= VELDGROOTTE || toY >= VELDGROOTTE)
		return false;
	if (fromX == toX && fromY == toY)
		return false;
	if (fromX == toX || fromY == toY)
		return true;
	if (toX - fromX == toY - fromY || toX - fromX == -(toY - fromY))
		return true;
	else
		return false;
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