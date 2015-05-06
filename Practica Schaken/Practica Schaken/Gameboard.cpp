#include <iostream>
#include "Gameboard.h"
#include "Game.h"

Gameboard::Gameboard(Game* game1)
{
	game = game1;
	initializeBoard();
	initializeDefeated();
	historySize = 0;
}

Gameboard::~Gameboard()
{

}

void Gameboard::initializeBoard()
{
	for (int i = 0; i < VELDGROOTTE; ++i)
	{
		for (int j = 0; j < VELDGROOTTE; ++j)
		{
			board[i][j] = NULL;
		}
	}
    // Put Soldiers
    for (int i = 0; i < VELDGROOTTE; ++i)
    {
        board[6][i] = new Piece(Piece::Color::BLACK, Piece::Type::SOLDIER);
        board[1][i] = new Piece(Piece::Color::WHITE, Piece::Type::SOLDIER);
    }
    // Put Towers
    board[7][0] = new Piece(Piece::Color::BLACK, Piece::Type::CASTLE);
    board[7][7] = new Piece(Piece::Color::BLACK, Piece::Type::CASTLE);
    board[0][0] = new Piece(Piece::Color::WHITE, Piece::Type::CASTLE);
    board[0][7] = new Piece(Piece::Color::WHITE, Piece::Type::CASTLE);

    // Put Horses
    board[7][1] = new Piece(Piece::Color::BLACK, Piece::Type::HORSE);
    board[7][6] = new Piece(Piece::Color::BLACK, Piece::Type::HORSE);
    board[0][1] = new Piece(Piece::Color::WHITE, Piece::Type::HORSE);
    board[0][6] = new Piece(Piece::Color::WHITE, Piece::Type::HORSE);
    
    // Put Bischops
    board[7][2] = new Piece(Piece::Color::BLACK, Piece::Type::BISCHOP);
    board[7][5] = new Piece(Piece::Color::BLACK, Piece::Type::BISCHOP);
    board[0][2] = new Piece(Piece::Color::WHITE, Piece::Type::BISCHOP);
    board[0][5] = new Piece(Piece::Color::WHITE, Piece::Type::BISCHOP);

    // King and Queen
    board[7][3] = new Piece(Piece::Color::BLACK, Piece::Type::KING);
    board[0][4] = new Piece(Piece::Color::WHITE, Piece::Type::KING);
    board[7][4] = new Piece(Piece::Color::BLACK, Piece::Type::QUEEN);
    board[0][3] = new Piece(Piece::Color::WHITE, Piece::Type::QUEEN);
}

bool Gameboard::move(Piece* piece, int fromX, int fromY, int toX, int toY)
{
	bool valid = false;
	valid = canMove(piece, fromX, fromY, toX, toY);
	valid &= game->isValidMove(*piece, fromX, fromY, toX, toY);
	if (valid)
	{
		if (board[toY][toX] == NULL)
			board[toY][toX] = piece;
		else if (board[toY][toX]->getColor() != piece->getColor())
		{
			addToDefeated(board[toY][toX], board[toY][toX]->getColor());
			board[toY][toX] = piece;

		}
		history = new Move[historySize + 1];
		history[historySize] = Move(piece, fromX, fromY, toX, toY);
		board[fromY][fromX] = NULL;
		historySize++;
		return true;
	}
	else
		return false;
	
}

bool Gameboard::canMove(Piece* piece, int fromX, int fromY, int toX, int toY)
{
	switch (piece->getType())
	{
		case Piece::Type::SOLDIER:
			bool first = false, valid = false;
			first = (piece->getColor() == Piece::Color::WHITE && fromY == 6) ||
					(piece->getColor() == Piece::Color::BLACK && fromY == 1);	

			valid = Move::canSoldMove(fromX, fromY, toX, toY, first, piece->getColor());
			valid |= Move::canSoldAttack(fromX, fromY, toX, toY, piece->getColor());

			return valid;
		// Rest cases komen hier
	}
	return false;
}

void Gameboard::printBoard()
{
	std::cout << "\n";
	std::cout << "\n-------------------------------------\n" << "|   |";
	for (int i = 0; i < VELDGROOTTE; ++i)
		std::cout << " " << (char)('A' + i) << " |";
	
	std::cout << "\n=====================================\n";
	for (int i = VELDGROOTTE - 1; i >= 0; --i)
	{
		std::cout << "| " << (i+1) << " |";
		for (int j = 0; j < VELDGROOTTE; ++j)
		{
			char c = ' ';
			Piece* p = board[i][j];
			if (p != NULL)
				c = p->getSymbol();

			if (p != NULL && p->getColor() == BLACK)
				std::cout << "_" << c << "_|";
			else
				std::cout << " " << c << " |";

		}
		std::cout << "\n-------------------------------------\n";
	}

	std::cout << "\n";
}

void Gameboard::initializeDefeated()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < VELDGROOTTE*2; ++j)
		{
			defeated[i][j] = NULL;
		}
	}
}
void Gameboard::addToDefeated(Piece* Piece, enum Piece::Color color)
{
	for (int i = VELDGROOTTE * 2 - 1; i >= 0; --i)
	{
		if (defeated[color][i] != NULL && i != VELDGROOTTE * 2 - 1)
			return;
		else if (defeated[color][i] != NULL)
			defeated[color][i + 1] = defeated[color][i];
	}
	defeated[color][0] = Piece;

}