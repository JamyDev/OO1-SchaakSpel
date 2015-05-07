#ifndef KNIGHT_H
#define KNIGHT_H 1
#include "Piece.h"

class Move;

class Knight : public Piece
{
	public:
		bool isValidMove(const Move& move, Game& game);
		Knight();
		Knight(enum Color colornum);

	private:

};
#endif