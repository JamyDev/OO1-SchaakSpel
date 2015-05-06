#ifndef KNIGHT_H
#define KNIGHT_H 1
#include "Piece.h"

class Knight : public Piece
{
	public:
		bool isValidMove(const Move& move, const Game& game);
		Knight();
		Knight(enum Color colornum);

	private:

};
#endif