/*
* Piece.h
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#ifndef PIECE_H
#define PIECE_H 1
#include "Gameboard.h"
class Piece
{
	public:
		//Defines which color the piece has.
		enum Color { WHITE, BLACK};
		//A piece can be any of the following types, possible moves and rules are based on these types.
		enum Type { PAWN, KNIGHT, ROOK, BISHOP, QUEEN, KING };
		//Constructors
		enum Color getColor() const;
		char getSymbol() const;
		enum Type getType() const;

		virtual bool isValidMove(const Move& move, const Game& game) = 0;
		int getX() const;
		int getY() const;
		void setNewPos(int newX, int newY);

	protected:
		enum Color color;
		enum Type type;

	private:
		int x;
		int y;
};
#endif