/*
* Move.h
* Authors: Jeroen Ceyssens
*/

#ifndef MOVE_H
#define MOVE_H
#include "Piece.h"

class Gameboard;
class Move
{
	public:
		//default constructor
		Move();
		//param constructor
		Move(Piece* usedPiece, int fromX, int fromY, int toX, int toY);
		int getToX() const;
		int getToY() const;

	private:
		Piece *piece;
		int originalX;
		int originalY;
		int newX;
		int newY;
};
#endif
