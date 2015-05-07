#ifndef PAWN_H
#define PAWN_H 1
#include "Piece.h"

class Game;

class Pawn: public Piece
{
	public:
		Pawn();
		Pawn(enum Color colornum);
		bool isValidMove(const Move& move, Game& game);
		bool isValidAttack(const Move& move, const Game& game) const;
		void setPos(int newX, int newY);
	private:
		bool isFirst;
};
#endif