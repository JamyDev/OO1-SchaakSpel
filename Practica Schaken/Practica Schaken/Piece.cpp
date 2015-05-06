/*
* Piece.cpp
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#include "Piece.h"

Piece::Color Piece::getColor() const
{
	return color;
}

Piece::Type Piece::getType() const
{
	return type;
}

char Piece::getSymbol() const
{
	switch (type)
	{
		case PAWN:
			return '^';
		case ROOK:
			return '#';
		case KNIGHT:
			return '%';
		case BISHOP:
			return '&';
		case KING:
			return '+';
		case QUEEN:
			return 'W';
		default:
			return ' ';
	}
}

int Piece::getX() const
{
	return x;
}

int Piece::getY() const
{
	return y;
}

void Piece::setNewPos(int newX, int newY)
{
	x = newX;
	y = newY;
}
