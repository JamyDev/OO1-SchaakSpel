#include "Knight.h"
#include "Gameboard.h"
#include "Game.h"

Knight::Knight()
{
	color = WHITE;
	type = KNIGHT;
}

Knight::Knight(enum Color colornum)
{
	color = colornum;
	type = KNIGHT;
}

bool Knight::isValidMove(const Move& move, Game& game)
{
	bool result = false;

	if (move.getToX() < 0 || move.getToY() < 0 || move.getToX() >= Gameboard::VELDGROOTTE || move.getToY() >= Gameboard::VELDGROOTTE)
		result = false;
	else if (getX() - 2 == move.getToX() && (getY() - 1 == move.getToY() || getY() + 1 == move.getToY()))
		result = true;
	else if (getX() + 2 == move.getToX() && (getY() - 1 == move.getToY() || getY() + 1 == move.getToY()))
		result = true;
	else if (getY() - 2 == move.getToY() && (getX() - 1 == move.getToX() || getX() + 1 == move.getToX()))
		result = true;
	else if (getY() + 2 == move.getToY() && (getX() - 1 == move.getToX() || getX() + 1 == move.getToX()))
		result = true;
	if (checkIfNoInterrupt(move, game.getGameboard()))
		return result;
	else
		return false;
}
