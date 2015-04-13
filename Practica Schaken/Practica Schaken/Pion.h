class Pion
{
public:
	//Defines which color the pion has.
	enum Color { BLACK, WHITE };
	//A pion can be any of the following types, possible moves and rules are based on these types.
	enum Type { SOLDIER, HORSE, CASTLE, BISCHOP, QUEEN, KING };
	//Constructors
	Pion();
	Pion(enum Color colornum, enum Type typenum);
private:
	enum Color color;
	enum Type type;
};