#include <iostream>
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
		<< " - q: Exit the game." << "\n";
}

void UI::printActivePlayerToConsole(Game& game)
{
	std::cout << "Active player: ";
	if (game.getActivePlayer() == Game::PlayerColor::WHITE) {
		std::cout << "White\n";
	}
	else {
		std::cout << "Black\n";
	}
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

	scanf("%c %c%i %c%i", &cmdC, &fromC, &fromY, &toC, &toY);
	flush_stdin();

	fromY--;
	toY--;

	fromX = (toupper(fromC) - 'A');
	toX = (toupper(toC) - 'A');

	Command cmd = getCommand(cmdC);
	if (cmd == MOVE)
	{
		lastMove = new Move(game.getGameboard()->getPieceAt(fromX, fromY), fromX, fromY, toX, toY);		
	}

	return cmd;
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
				std::cout << "_" << c << "_|";
			else
				std::cout << " " << c << " |";

		}
		std::cout << "\n-------------------------------------\n";
	}

	std::cout << "\n";
}

void askForMoveConsole()
{

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