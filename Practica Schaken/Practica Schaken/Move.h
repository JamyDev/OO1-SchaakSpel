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

		//booleans that check which moves the pions can do
		static bool canHorseMove(int fromX, int fromY, int toX, int toY);
		static bool canPawnMove(int fromX, int fromY, int toX, int toY, bool isFirst, enum Piece::Color color);
		static bool canPawnAttack(int fromX, int fromY, int toX, int toY, enum Piece::Color color);
		static bool canKnightMove(int fromX, int fromY, int toX, int toY);
		static bool canBissMove(int fromX, int fromY, int toX, int toY);
		static bool canQueenMove(int fromX, int fromY, int toX, int toY);
		static bool canKingMove(int fromX, int fromY, int toX, int toY);

	private:
		Piece *piece;
		int originalX;
		int originalY;
		int newX;
		int newY;
};
#endif
