#include <iostream>
#include <conio.h>
#include "spel.h"


int main(void)
{
	std::cout << "Chess by Jamy and Jeroen" << "\n" <<
		"Shall we play a game?";
	//_getche();
	Spel* spel = new Spel();
	spel->startSpel();
	spel->getSpelbord()->printBoard();

	delete spel;
	return 0;

}