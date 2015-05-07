/*
* Piece.h
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#ifndef PIECE_H
#define PIECE_H 1

#include "Move.h"

class Gameboard;
class Game;

class Piece
{
	public:
		//Defines which color the piece has.
		static const enum Color { WHITE, BLACK};
		//A piece can be any of the following types, possible moves and rules are based on these types.
		static const enum Type { PAWN, KNIGHT, ROOK, BISHOP, QUEEN, KING };

		enum Color getColor() const;
		char getSymbol() const;
		enum Type getType() const;

		virtual bool isValidMove(const Move& move, Game& gameboard) = 0;
		bool checkIfNoInterrupt( const Move& move, Gameboard* gameboard);
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