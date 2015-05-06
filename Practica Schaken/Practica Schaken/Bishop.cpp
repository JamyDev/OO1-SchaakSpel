#include "Bishop.h"

Bishop::Bishop()
{
	color = WHITE;
	type = BISHOP;
}

Bishop::Bishop(enum Color colornum)
{
	color = colornum;
	type = BISHOP;
}

bool Bishop::isValidMove(const Move& move, Game& game)
{
	bool result = false;
	if (move.getToX() < 0 || move.getToY() < 0 || move.getToX() >= VELDGROOTTE || move.getToY() >= VELDGROOTTE)
		result = false;
	else if (getX() == move.getToX() && getY() == move.getToY())
		result = false;
	else if (move.getToX() - getX() == move.getToY() - getY() || move.getToX() - getX() == -(move.getToY() - getY()))
		result = true;
	if (checkIfNoInterrupt(move, game.getGameboard))
		return result;
	else
		return false;
}