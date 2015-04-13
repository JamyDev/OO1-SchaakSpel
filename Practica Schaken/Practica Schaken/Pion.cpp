/*
* Pion.cpp
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#include "Pion.h"

Pion::Pion()
{
	color = WHITE;
	type = SOLDIER;
}
Pion::Pion(enum Color colornum, enum Type typenum)
{
	color = colornum;
	type = typenum;
}

Pion::Color Pion::getColor()
{
	return color;
}

Pion::Type Pion::getType()
{
	return type;
}

char Pion::getSymbol()
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