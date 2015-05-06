#ifndef BISHOP_H
#define BISHOP_H 1
#include "Piece.h"

class Bishop : public Piece
{
	public:
		bool isValidMove(const Move& move, const Game& game);
		Bishop();
		Bishop(enum Color colornum);

	private:

};
#endif