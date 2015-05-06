#ifndef PAWN_H
#define PAWN_H 1
#include "Piece.h"

class Pawn: public Piece
{
	public:
		Pawn();
		Pawn(enum Color colornum);
		bool Pawn::isValidMove(const Move& move, const Game& game);
		void setPos(int newX, int newY);

	private:
		bool isFirst;
};
#endif