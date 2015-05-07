#include "Rook.h"
#include "Gameboard.h"
#include "Game.h"

Rook::Rook()
{
	color = WHITE;
	type = ROOK;
}

Rook::Rook(enum Color colornum)
{
	color = colornum;
	type = ROOK;
}

bool Rook::isValidMove(const Move& move, Game& game)
{
	bool result = false;
	if (move.getToX() < 0 || move.getToY() < 0 || move.getToX() >= Gameboard::VELDGROOTTE || move.getToY() >= Gameboard::VELDGROOTTE)
		return false;
	else if (getX() == move.getToX() && getY() == move.getToY())
		return false;
	else if (getX() == move.getToX() || getY() == move.getToY())
		result = true;
	if (checkIfNoInterrupt(move, game.getGameboard()))
		return result;
	else
		return false;
}
