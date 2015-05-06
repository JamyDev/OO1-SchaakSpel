#include "Queen.h"

Queen::Queen()
{
	color = WHITE;
	type = QUEEN;
}

Queen::Queen(enum Color colornum)
{
	color = colornum;
	type = QUEEN;
}
