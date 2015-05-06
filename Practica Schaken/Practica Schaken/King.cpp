#include "King.h"

King::King()
{
	color = WHITE;
	type = KING;
}

King::King(enum Color colornum)
{
	color = colornum;
	type = KING;
}
