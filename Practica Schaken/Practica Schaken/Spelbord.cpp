#include <iostream>
#include "Spelbord.h"

Spelbord::Spelbord()
{
	initializeBoard();
}

Spelbord::~Spelbord()
{

}

void Spelbord::initializeBoard()
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
		board[6][i] = new Pion(Pion::Color::WHITE, Pion::Type::SOLDIER);
		board[1][i] = new Pion(Pion::Color::BLACK, Pion::Type::SOLDIER);
	}
	// Put Towers
	board[7][0] = new Pion(Pion::Color::WHITE, Pion::Type::CASTLE);
	board[7][7] = new Pion(Pion::Color::WHITE, Pion::Type::CASTLE);
	board[0][0] = new Pion(Pion::Color::BLACK, Pion::Type::CASTLE);
	board[0][7] = new Pion(Pion::Color::BLACK, Pion::Type::CASTLE);

	// Put Horses
	board[7][1] = new Pion(Pion::Color::WHITE, Pion::Type::HORSE);
	board[7][6] = new Pion(Pion::Color::WHITE, Pion::Type::HORSE);
	board[0][1] = new Pion(Pion::Color::BLACK, Pion::Type::HORSE);
	board[0][6] = new Pion(Pion::Color::BLACK, Pion::Type::HORSE);
	
	// Put Bischops
	board[7][2] = new Pion(Pion::Color::WHITE, Pion::Type::BISCHOP);
	board[7][5] = new Pion(Pion::Color::WHITE, Pion::Type::BISCHOP);
	board[0][2] = new Pion(Pion::Color::BLACK, Pion::Type::BISCHOP);
	board[0][5] = new Pion(Pion::Color::BLACK, Pion::Type::BISCHOP);

	// King and Queen
	board[7][3] = new Pion(Pion::Color::WHITE, Pion::Type::KING);
	board[0][4] = new Pion(Pion::Color::BLACK, Pion::Type::KING);
	board[7][4] = new Pion(Pion::Color::WHITE, Pion::Type::QUEEN);
	board[0][3] = new Pion(Pion::Color::BLACK, Pion::Type::QUEEN);
}

bool Spelbord::canMove(Pion pion, int fromX, int fromY, int toX, int toY)
{
	return false;
}

void Spelbord::printBoard()
{
	std::cout << "\n";
	std::cout << "\n-------------------------------------\n" << "|   |";
	for (int i = 0; i < VELDGROOTTE; ++i)
		std::cout << " " << (char)('A' + i) << " |";
	
	std::cout << "\n=====================================\n";
	for (int i = VELDGROOTTE - 1; i >= 0; --i)
	{
		std::cout << "| " << i << " |";
		for (int j = 0; j < VELDGROOTTE; ++j)
		{
			char c = ' ';
			Pion* p = board[i][j];
			if (p != NULL)
				c = p->getSymbol();

			std::cout << " " << c << " |";
		}
		std::cout << "\n-------------------------------------\n";
	}

	std::cout << "\n";
}
