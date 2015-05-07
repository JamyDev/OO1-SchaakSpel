#include "King.h"
#include "Gameboard.h"

King::King()
{
	color = WHITE;
	type = KING;
}

King::King(enum Color colornum)
{
	color = colornum;
	type = KING;
}
bool King::isValidMove(const Move& move, Game& game)
{
	bool result = false;
	if (move.getToX() < 0 || move.getToY() < 0 || move.getToX() >= Gameboard::VELDGROOTTE || move.getToY() >= Gameboard::VELDGROOTTE)
		return false;
	if (getX() == move.getToX() && getY() == move.getToY())
		return false;
	if (getX() - 1 == move.getToX() || getY() - 1 == move.getToY() || getX() + 1 == move.getToX() || getY() + 1 == move.getToY())
		return true;
	else
		return false;
}