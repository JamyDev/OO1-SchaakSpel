#ifndef UI_H
#define UI_H

#include "Gameboard.h"
#include "Move.h"

class Game;

class UI {
	public:
		UI();
		static const enum Command {MOVE, HELP, SAVE, LOAD, QUIT};
		void displayBoard(Gameboard& board);
		enum Command askCommand(Game& game);
		void showActivePlayer(Game& game);
		void showError(char* error);
		void showHelp();
		char askPromotion();
		Move* getLastMove();
	private:
		static const enum UIType {CONSOLE};
		enum UIType uiType = CONSOLE;
		Move* lastMove;
		void printBoardToConsole(Gameboard& board);
		void printActivePlayerToConsole(Game& game);
		void printHelpToConsole();
		char askPromotionConsole();
		void printErrorToConsole(char* error);
		static void flush_stdin();
		static enum Command getCommand(char c);
		enum Command askCommandConsole(Game& game);
};
#endif