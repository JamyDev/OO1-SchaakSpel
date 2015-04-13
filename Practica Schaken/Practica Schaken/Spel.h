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
		bool isLegaleZet(Pion &pion, int naarX, int naarY);

	private:
		Spelbord *spelbord;
		enum PlayerColor activePlayer;

};
#endif
