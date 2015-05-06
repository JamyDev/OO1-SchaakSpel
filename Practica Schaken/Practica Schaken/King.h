#ifndef KING_H
#define KING_H 1
#include "Piece.h"

class King : public Piece
{
	public:
		bool isValidMove(const Move& move, const Game& game);
		King();
		King(enum Color color);

	private:

};
#endif