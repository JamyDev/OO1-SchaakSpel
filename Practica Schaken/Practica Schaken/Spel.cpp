#include "Spel.h"

Spel::Spel()
{
	spelbord = new Spelbord;
	activePlayer = WHITE;
}
Spel::~Spel()
{
	delete spelbord;
}
