/*
* Piece.h
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#ifndef PION_H
#define PION_H
class Piece
{
	public:
		//Defines which color the piece has.
		enum Color { WHITE, BLACK};
		//A piece can be any of the following types, possible moves and rules are based on these types.
		enum Type { SOLDIER, HORSE, CASTLE, BISCHOP, QUEEN, KING };
		//Constructors
		Piece();
		Piece(enum Color colornum, enum Type typenum);
		enum Color getColor();
		char getSymbol();
		enum Type getType();
	private:
		enum Color color;
		enum Type type;
};
#endif