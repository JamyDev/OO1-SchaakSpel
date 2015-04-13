#ifndef PION_H
#define PION_H
class Pion
{
	public:
		//Defines which color the pion has.
		enum Color { WHITE, BLACK};
		//A pion can be any of the following types, possible moves and rules are based on these types.
		enum Type { SOLDIER, HORSE, CASTLE, BISCHOP, QUEEN, KING };
		//Constructors
		Pion();
		Pion(enum Color colornum, enum Type typenum);
		enum Color getColor();
		char getSymbol();
		enum Type getType();
	private:
		enum Color color;
		enum Type type;
};
#endif