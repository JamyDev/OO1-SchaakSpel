#include <iostream>
#include <conio.h>
#include "UI.h"
#include "Game.h"
#include "Move.h"


UI::UI() 
{
	std::cout << "Welcome to CHESS" << "\n";
	printHelpToConsole();
}

void UI::printHelpToConsole()
{
	std::cout
		<< "Commands: \n"
		<< " - m <row><col> <row><col>: Move from first to second position (e.g.: m B2 B4)" << "\n"
		<< " - ?: Shows this help text." << "\n"
		<< " - s: Saves the game." << "\n"
		<< " - l: Loads the game." << "\n"
		<< " - q: Exit the game." << "\n"
		<< "Press any key to continue...";
	_getche();
}

void UI::showHelp()
{
	if (uiType == CONSOLE)
		printHelpToConsole();
}

void UI::printActivePlayerToConsole(Game& game)
{
	std::cout
		<< "["
		<< ((game.getActivePlayer() == Game::PlayerColor::WHITE) ? "WHITE" : "BLACK")
		<< "] Please enter a command (Or '?' for help): ";
}

void UI::displayBoard(Gameboard& board)
{
	if (uiType == CONSOLE) {
		printBoardToConsole(board);
	}
}

void UI::showActivePlayer(Game& game)
{
	if (uiType == CONSOLE) {
		printActivePlayerToConsole(game);
	}
}

Move* UI::getLastMove()
{
	Move* last = lastMove;
	lastMove = NULL;
	return last;
}

enum UI::Command UI::askCommand(Game& game)
{
	if (uiType == CONSOLE) {
		return askCommandConsole(game);
	}
}

enum UI::Command UI::askCommandConsole(Game& game)
{
	char cmdC, fromC, toC;
	int fromX, fromY, toX, toY;
	cmdC = _getche();

	Command cmd = getCommand(cmdC);
	
	if (cmd == Command::MOVE)
	{
		scanf(" %c%i %c%i", &fromC, &fromY, &toC, &toY);
		flush_stdin();
	
		fromY--;
		toY--;

		fromX = (toupper(fromC) - 'A');
		toX = (toupper(toC) - 'A');

		lastMove = new Move(game.getGameboard()->getPieceAt(fromX, fromY), fromX, fromY, toX, toY);		
	}

	return cmd;
}

void UI::showError(char* error)
{
	if (uiType == CONSOLE)
	{
		printErrorToConsole(error);
	}
}

void UI::printErrorToConsole(char* error)
{
	std::cout << error << "\n";
}

void UI::printBoardToConsole(Gameboard& board)
{
	std::cout << "\n";
	std::cout << "\n-------------------------------------\n" << "|   |";
	for (int i = 0; i < Gameboard::VELDGROOTTE; ++i)
		std::cout << " " << (char)('A' + i) << " |";

	std::cout << "\n=====================================\n";
	for (int i = Gameboard::VELDGROOTTE - 1; i >= 0; --i)
	{
		std::cout << "| " << (i + 1) << " |";
		for (int j = 0; j < Gameboard::VELDGROOTTE; ++j)
		{
			char c = ' ';
			Piece* p = board.getPieceAt(j, i);
			if (p != NULL)
				c = p->getSymbol();

			if (p != NULL && p->getColor() == Piece::Color::BLACK)
				std::cout << "[" << c << "]|";
			else
				std::cout << " " << c << " |";

		}
		std::cout << "\n-------------------------------------\n";
	}

	std::cout << "\n";
}

char UI::askPromotion()
{
	if (uiType == CONSOLE)
		return askPromotionConsole();
}

char UI::askPromotionConsole()
{
	char prom = 0;
	while (prom == 0)
	{
		std::cout << "What would you like to promote your pawn to? (R = Rook, B = Bishop, H = Knight, Q = Queen): ";
		prom = toupper(_getche());
		if (prom != 'R' && prom != 'B' && prom != 'H' && prom != 'Q')
			prom = 0;
	}

	return prom;
}

/* Flush the stdin buffer (scanf leaves \n there)
This way fgets on stdin doesn't just skip. */
void UI::flush_stdin()
{
	char c;
	while ((c = (char)getchar()) != '\n' && c != EOF);
}

enum UI::Command UI::getCommand(char c)
{
	switch (c)
	{
	case 'm':
		return UI::Command::MOVE;
	case '?':
		return UI::Command::HELP;
	case 's':
		return UI::Command::SAVE;
	case 'l':
		return UI::Command::LOAD;
	case 'q':
		return UI::Command::QUIT;
	}
}