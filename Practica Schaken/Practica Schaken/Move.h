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
		//Get and set inline-functions for the newX and Y 
		int getToX() const { return newX; }
		int getToY() const { return newY; }
		void setToX(int toX) { newX = toX; }
		void setToY(int toY) { newY = toY; }
		//Get and set inline-functions to for the originalX and Y
		int getFromX() const { return newX; }
		int getFromY() const { return newY; }
		void setFromX(int fromX) { originalX = fromX; }
		void setFromY(int fromY) { originalY = fromY; }

	private:
		Piece *piece;
		int originalX;
		int originalY;
		int newX;
		int newY;
};
#endif
