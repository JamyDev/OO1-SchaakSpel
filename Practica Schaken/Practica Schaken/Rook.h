#ifndef ROOK_H
#define ROOK_H 1
#include "Piece.h"

class Rook : public Piece
{
	public:
		bool isValidMove(const Move& move, Game& game);
		Rook();
		Rook(enum Color colornum);

};
#endif