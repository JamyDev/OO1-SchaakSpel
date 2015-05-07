#include "Gameboard.h"

class Game;
class FileIO
{
	public:
		static void putToFile(Game& game);
		static void getBoardFromFile(Gameboard* gameboard);
		//0 = WHITE and 1 = BLACK
		static int getActivePlayer();
};