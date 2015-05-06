#include "Queen.h"

Queen::Queen()
{
	color = WHITE;
	type = QUEEN;
}

Queen::Queen(enum Color colornum)
{
	color = colornum;
	type = QUEEN;
}

bool Queen::isValidMove(const Move& move, Game& game)
{
	bool result = false;
	if (move.getToX() < 0 || move.getToY() < 0 || move.getToX() >= Gameboard::VELDGROOTTE || move.getToY() >= Gameboard::VELDGROOTTE)
		result = false;
	else if (getX() == move.getToX() && getY() == move.getToY())
		result = false;
	else if (getX() == move.getToX() || getY() == move.getToY())
		result = true;
	else if (move.getToX() - getX() == move.getToY() - getY() || move.getToX() - getX() == -(move.getToY() - getY()))
		result = true;
	if (checkIfNoInterrupt(move, game.getGameboard()))
		return result;
	else
		return false;
}