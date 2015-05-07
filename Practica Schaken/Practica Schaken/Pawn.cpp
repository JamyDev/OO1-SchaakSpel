#include "Pawn.h"
#include "Gameboard.h"
#include "Game.h"
#include <stdlib.h>

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

bool Pawn::isValidMove(const Move& move, Game& game)
{
	bool result = false;
	if (move.getToX() < 0 || move.getToY() < 0 || move.getToX() >= Gameboard::VELDGROOTTE || move.getToY() >= Gameboard::VELDGROOTTE)
		return false;
	if (isValidAttack(move, game))
		return true;
	if (color == Piece::BLACK)
	{
		if (getX() == move.getToX() && getY() - 1 == move.getToY())
			result =  true;
		else if (getX() == move.getToX() && getY() - 2 == move.getToY() && isFirst == true)
			result = true;
		else
			result = false;
	}
	else if (color == Piece::WHITE)
	{
		if (getX() == move.getToX() && getY() + 1 == move.getToY())
			result = true;
		else if (getX() == move.getToX() && getY() + 2 == move.getToY() && isFirst == true)
			result = true;
		else
			result = false;
	}
	if (checkIfNoInterrupt(move, game.getGameboard()))
		return result;

	return false;
}

bool Pawn::isValidAttack(const Move& move, Game& game) const
{
	if (move.getToX() < 0 || move.getToY() < 0 || move.getToX() >= Gameboard::VELDGROOTTE || move.getToY() >= Gameboard::VELDGROOTTE)
		return false;
	if (color == Piece::BLACK)
	{
		if (getX() - 1 == move.getToX() && getY() - 1 == move.getToY() && 
			game.getGameboard()->getPieceAt(move.getToX(), move.getToY())->getColor() == WHITE)
			return true;
		else if (getX() + 1 == move.getToX() && getY() - 1 == move.getToY() &&
			game.getGameboard()->getPieceAt(move.getToX(), move.getToY())->getColor() == WHITE)
			return true;
		else
			return false;
	}
	else if (color == Piece::WHITE)
	{
		if (getX() - 1 == move.getToX() && getY() + 1 == move.getToY() &&
			game.getGameboard()->getPieceAt(move.getToX(), move.getToY())->getColor() == BLACK)
			return true;
		else if (getX() + 1 == move.getToX() && getY() + 1 == move.getToY() &&
			game.getGameboard()->getPieceAt(move.getToX(), move.getToY())->getColor() == BLACK)
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