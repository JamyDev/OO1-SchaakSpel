#ifndef PIECE_H
#define PIECE_H
class Piece
{
	public:
		//Defines which color the Piece has.
		enum Color { WHITE, BLACK};
		//A Piece can be any of the following types, possible moves and rules are based on these types.
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