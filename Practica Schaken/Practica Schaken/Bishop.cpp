#include "Bishop.h"

Bishop::Bishop()
{
	color = WHITE;
	type = BISHOP;
}

Bishop::Bishop(enum Color colornum)
{
	color = colornum;
	type = BISHOP;
}
