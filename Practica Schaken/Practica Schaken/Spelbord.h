#include "Pion.h"
const int VELDGROOTTE = 8;

class Spel;
class Spelbord {
	public:
		void initializeBoard();
		bool canMove(Pion pion, int fromX, int fromY, int toX, int toY);
	private:
		
		Pion veld[VELDGROOTTE][VELDGROOTTE];
};