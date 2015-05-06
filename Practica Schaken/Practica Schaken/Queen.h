#ifndef QUEEN_H
#define QUEEN_H 1
#include "Piece.h"

class Queen : public Piece
{
	public:
		bool isValidMove(const Move& move, const Game& game);
		Queen();
		Queen(enum Color colornum);

	private:

};
#endif