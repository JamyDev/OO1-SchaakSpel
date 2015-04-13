/*
* Spelbord.h
* Authors: Jamy Timmermans
*/

#ifndef SPELBORD_H
#define SPELBORD_H
#include "Pion.h"
#include "Zet.h"

const int VELDGROOTTE = 8;

class Spel;

class Spelbord 
{
	public:
		Spelbord(Spel* spel1);
		~Spelbord();
		void initializeBoard();
		bool canMove(Pion* pion, int fromX, int fromY, int toX, int toY);
		bool move(Pion* pion, int fromX, int fromY, int toX, int toY);
		void printBoard();
		Pion* board[VELDGROOTTE][VELDGROOTTE];
	private:
		Spel* spel;
		Zet* history;
		Pion* defeated[2][16];
		int historySize;
		void initializeDefeated();
		void addToDefeated(Pion* pion, enum Pion::Color color);
};
#endif
