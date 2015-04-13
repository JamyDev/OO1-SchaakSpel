#include <stdlib.h>
#include "Zet.h"
#include "Spelbord.h"

Zet::Zet()
{
	pion = NULL;
	originalX = 0;
	originalY = 0;
	newX = 0;
	newY = 0;
}

Zet::Zet(Pion* usedPion, int fromX, int fromY, int toX, int toY)
{
	pion = usedPion;
	originalX = fromX;
	originalY = fromY;
	newX = toX;
	newY = toY;
}

bool Zet::canHorseMove(int fromX, int fromY, int toX, int toY)
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

bool Zet::canSoldMove(int fromX, int fromY, int toX, int toY, bool isFirst, enum Pion::Color color)
{
	if (toX < 0 || toY < 0 || toX >= VELDGROOTTE || toY >= VELDGROOTTE)
		return false;
	if (color == Pion::BLACK)
	{
		if (fromX == toX && fromY + 1 == toY)
			return true;
		else if (fromX == toX && fromY + 2 == toY && isFirst == true)
			return true;
		else
			return false;
	}
	else if (color == Pion::WHITE)
	{
		if (fromX == toX && fromY - 1 == toY)
			return true;
		else if (fromX == toX && fromY - 2 == toY && isFirst == true)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Zet::canSoldAttack(int fromX, int fromY, int toX, int toY, enum Pion::Color color)
{
	if (toX < 0 || toY < 0 || toX >= VELDGROOTTE || toY >= VELDGROOTTE)
		return false;
	if (color == Pion::BLACK)
	{
		if (fromX + 1 == toX && fromY + 1 == toY)
			return true;
		else if (fromX - 1 == toX && fromY + 1 == toY)
			return true;
		else
			return false;
	}
	else if (color == Pion::WHITE)
	{
		if (fromX + 1 == toX && fromY - 1 == toY)
			return true;
		else if (fromX - 1 == toX && fromY - 1 == toY)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Zet::canCastleMove(int fromX, int fromY, int toX, int toY)
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

bool Zet::canBissMove(int fromX, int fromY, int toX, int toY)
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

bool Zet::canQueenMove(int fromX, int fromY, int toX, int toY)
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

bool Zet::canKingMove(int fromX, int fromY, int toX, int toY)
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