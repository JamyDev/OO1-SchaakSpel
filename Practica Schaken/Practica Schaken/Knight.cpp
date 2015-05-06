#include "Knight.h"

Knight::Knight()
{
	color = WHITE;
	type = KNIGHT;
}

Knight::Knight(enum Color colornum)
{
	color = colornum;
	type = KNIGHT;
}
