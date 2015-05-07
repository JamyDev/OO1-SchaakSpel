#ifndef UI_H
#define UI_H

#include "Gameboard.h"

class UI {
	public:
		void displayBoard(Gameboard board);
		void askForMove();
	private:
		static const enum UIType {CONSOLE};
		enum UIType uiType;
		void printBoardToConsole(Gameboard board);
		void askForMoveConsole();
};
#endif