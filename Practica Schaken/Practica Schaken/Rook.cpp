#include "Rook.h"

Rook::Rook()
{
	color = WHITE;
	type = ROOK;
}

Rook::Rook(enum Color colornum)
{
	color = colornum;
	type = ROOK;
}
