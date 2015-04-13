#include "Spelbord.h"
#include "Pion.h"

class Spel {
	public:
		Spel();
		void startSpel();
		bool isLegaleZet(Pion &pion, int naarX, int naarY);

	private:
		Spelbord *spelbord;
};
