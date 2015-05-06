#include "Pawn.h"

Pawn::Pawn()
{
	color = WHITE;
	type = PAWN;
	isFirst = true;
}

Pawn::Pawn(enum Color colornum)
{
	color = colornum;
	type = PAWN;
	isFirst = true;
}

bool Pawn::isValidMove(const Move& move, const Game& game)
{
	if (move.getToX() < 0 || move.getToY() < 0 || move.getToX() >= VELDGROOTTE || move.getToY() >= VELDGROOTTE)
		return false;
	if (color == Piece::BLACK)
	{
		if (getX() == move.getToX() && getY() - 1 == move.getToY())
			return true;
		else if (getX() == move.getToX() && getY() - 2 == move.getToY() && isFirst == true)
			return true;
		else
			return false;
	}
	else if (color == Piece::WHITE)
	{
		if (getX() == move.getToX() && getY() + 1 == move.getToY())
			return true;
		else if (getX() == move.getToX() && getY() + 2 == move.getToY() && isFirst == true)
			return true;
		else
			return false;
	}
	else
		return false;
}

void Pawn::setPos(int newX, int newY)
{
	setNewPos(newX, newY);
	isFirst = false;
}