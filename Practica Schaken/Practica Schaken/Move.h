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
		//booleans that check which moves the Pieces can do
		static bool canHorseMove(int fromX, int fromY, int toX, int toY);
		static bool canSoldMove(int fromX, int fromY, int toX, int toY, bool isFirst, enum Piece::Color color);
		static bool canSoldAttack(int fromX, int fromY, int toX, int toY, enum Piece::Color color);
		static bool canCastleMove(int fromX, int fromY, int toX, int toY);
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
