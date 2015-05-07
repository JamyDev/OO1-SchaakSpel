/*
* Piece.cpp
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#include "Piece.h"
#include "Gameboard.h"
#include "Game.h"
#include <stdlib.h>

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
			return 'R';
		case KNIGHT:
			return 'H';
		case BISHOP:
			return 'B';
		case KING:
			return 'K';
		case QUEEN:
			return 'Q';
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

bool Piece::checkIfNoInterrupt(const Move& move, Gameboard* gameboard)
{
	int differenceX = move.getToX() - getX();
	int differenceY = move.getToY() - getY();
	int i, j;
	if (differenceX < 0 && differenceY < 0)
		for (i = getX() - 1, j = getY() - 1; i > move.getToX() && j > move.getToY(); --i, --j)
			if (gameboard->isPieceAt(i, j))
				return false;
	else if (differenceX > 0 && differenceY < 0)
		for (i = getX() + 1, j = getY() - 1; i < move.getToX() && j > move.getToY(); ++i, --j)
			if (gameboard->isPieceAt(i, j) != NULL)
				return false;
	else if (differenceX < 0 && differenceY > 0)
		for (i = getX() - 1, j = getY() + 1; i > move.getToX() && j < move.getToY(); --i, ++j)
			if (gameboard->isPieceAt(i, j) != NULL)
				return false;
	else if (differenceX > 0 && differenceY > 0)
		for (i = getX() + 1, j = getY() + 1; i < move.getToX() && j < move.getToY(); ++i, ++j)
			if (gameboard->isPieceAt(i, j) != NULL)
				return false;
	return true;
}

Piece* Piece::getPromotedPiece(char type)
{
	Piece* newPiece;
	if (getType() != PAWN)
		return NULL;
	if (type == 'r' || type == 'R')
	{
		newPiece = new Rook(getColor());
		newPiece->setNewPos(getX(), getY());
	}
	else if (type == 'b' || type == 'B')
	{
		newPiece = new Bishop(getColor());
		newPiece->setNewPos(getX(), getY());
	}
	else if (type == 'q' || type == 'Q')
	{
		newPiece = new Queen(getColor());
		newPiece->setNewPos(getX(), getY());
	}
	else if (type == 'k' || type == 'K')
	{
		newPiece = new Knight(getColor());
		newPiece->setNewPos(getX(), getY());
	}
	else
		return NULL;
	return newPiece;
}