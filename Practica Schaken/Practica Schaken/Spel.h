/*
* Spel.h
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#ifndef SPEL_H
#define SPEL_H

#include "Spelbord.h"
#include "Pion.h"

enum PlayerColor { WHITE, BLACK };

class Spel 
{
	public:
		Spel();
		~Spel();
		void startSpel();
		bool isValidMove(Pion* pion, int fromX, int fromY, int toX, int toY);
		Spelbord* getSpelbord();

	private:
		Spelbord *spelbord;
		enum PlayerColor activePlayer;

};
#endif
