/*
* Piece.cpp
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#include "Piece.h"

Piece::Piece()
{
	color = WHITE;
	type = SOLDIER;
}
Piece::Piece(enum Color colornum, enum Type typenum)
{
	color = colornum;
	type = typenum;
}

Piece::Color Piece::getColor()
{
	return color;
}

Piece::Type Piece::getType()
{
	return type;
}

char Piece::getSymbol()
{
	switch (type)
	{
		case SOLDIER:
			return '^';
		case CASTLE:
			return '#';
		case HORSE:
			return '%';
		case BISCHOP:
			return '&';
		case KING:
			return '+';
		case QUEEN:
			return 'W';
		default:
			return ' ';
	}
}