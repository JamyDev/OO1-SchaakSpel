#include "Pion.h"

Pion::Pion()
{
	color = WHITE;
	type = SOLDIER;
}
Pion::Pion(enum Color colornum, enum Type typenum)
{
	color = colornum;
	type = typenum;
}