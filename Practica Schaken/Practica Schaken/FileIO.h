#include "Gameboard.h"

class Game;
class FileIO
{
	public:
		void putToFile(Game& game);
		void getBoardFromFile(Gameboard* gameboard);
		//0 = WHITE and 1 = BLACK
		int getActivePlayer();
};