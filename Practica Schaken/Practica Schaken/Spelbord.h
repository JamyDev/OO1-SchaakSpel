#ifndef SPELBORD_H
#define SPELBORD_H
#include "Pion.h"
#include "Zet.h"

const int VELDGROOTTE = 8;

class Spel;

class Spelbord 
{
	public:
		Spelbord();
		~Spelbord();
		void initializeBoard();
		bool canMove(Pion* pion, int fromX, int fromY, int toX, int toY);
		void printBoard();
		Pion* board[VELDGROOTTE][VELDGROOTTE];
	private:
		Zet* history;
		Pion defeated[];
};
#endif
