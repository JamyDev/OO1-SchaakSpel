#include <iostream>
#include "Spelbord.h"
#include "Spel.h"

Spelbord::Spelbord(Spel* spel1)
{
	spel = spel1;
	initializeBoard();
	initializeDefeated();
	historySize = 0;
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
        board[6][i] = new Pion(Pion::Color::BLACK, Pion::Type::SOLDIER);
        board[1][i] = new Pion(Pion::Color::WHITE, Pion::Type::SOLDIER);
    }
    // Put Towers
    board[7][0] = new Pion(Pion::Color::BLACK, Pion::Type::CASTLE);
    board[7][7] = new Pion(Pion::Color::BLACK, Pion::Type::CASTLE);
    board[0][0] = new Pion(Pion::Color::WHITE, Pion::Type::CASTLE);
    board[0][7] = new Pion(Pion::Color::WHITE, Pion::Type::CASTLE);

    // Put Horses
    board[7][1] = new Pion(Pion::Color::BLACK, Pion::Type::HORSE);
    board[7][6] = new Pion(Pion::Color::BLACK, Pion::Type::HORSE);
    board[0][1] = new Pion(Pion::Color::WHITE, Pion::Type::HORSE);
    board[0][6] = new Pion(Pion::Color::WHITE, Pion::Type::HORSE);
    
    // Put Bischops
    board[7][2] = new Pion(Pion::Color::BLACK, Pion::Type::BISCHOP);
    board[7][5] = new Pion(Pion::Color::BLACK, Pion::Type::BISCHOP);
    board[0][2] = new Pion(Pion::Color::WHITE, Pion::Type::BISCHOP);
    board[0][5] = new Pion(Pion::Color::WHITE, Pion::Type::BISCHOP);

    // King and Queen
    board[7][3] = new Pion(Pion::Color::BLACK, Pion::Type::KING);
    board[0][4] = new Pion(Pion::Color::WHITE, Pion::Type::KING);
    board[7][4] = new Pion(Pion::Color::BLACK, Pion::Type::QUEEN);
    board[0][3] = new Pion(Pion::Color::WHITE, Pion::Type::QUEEN);
}

bool Spelbord::move(Pion* pion, int fromX, int fromY, int toX, int toY)
{
	bool valid = false;
	valid = canMove(pion, fromX, fromY, toX, toY);
	valid &= spel->isValidMove(*pion, fromX, fromY, toX, toY);
	if (valid)
	{
		if (board[toY][toX] == NULL)
			board[toY][toX] = pion;
		else if (board[toY][toX]->getColor() != pion->getColor())
		{
			addToDefeated(board[toY][toX], board[toY][toX]->getColor());
			board[toY][toX] = pion;

		}
		history = new Zet[historySize + 1];
		history[historySize] = Zet(pion, fromX, fromY, toX, toY);
		board[fromY][fromX] = NULL;
		historySize++;
		return true;
	}
	else
		return false;
	
}

bool Spelbord::canMove(Pion* pion, int fromX, int fromY, int toX, int toY)
{
	switch (pion->getType())
	{
		case Pion::Type::SOLDIER:
			bool first = false, valid = false;
			first = (pion->getColor() == Pion::Color::WHITE && fromY == 6) ||
					(pion->getColor() == Pion::Color::BLACK && fromY == 1);	

			valid = Zet::canSoldMove(fromX, fromY, toX, toY, first, pion->getColor());
			valid |= Zet::canSoldAttack(fromX, fromY, toX, toY, pion->getColor());

			return valid;
		// Rest cases komen hier
	}
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
		std::cout << "| " << (i+1) << " |";
		for (int j = 0; j < VELDGROOTTE; ++j)
		{
			char c = ' ';
			Pion* p = board[i][j];
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

void Spelbord::initializeDefeated()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < VELDGROOTTE*2; ++j)
		{
			defeated[i][j] = NULL;
		}
	}
}
void Spelbord::addToDefeated(Pion* pion, enum Pion::Color color)
{
	for (int i = VELDGROOTTE * 2 - 1; i >= 0; --i)
	{
		if (defeated[color][i] != NULL && i != VELDGROOTTE * 2 - 1)
			return;
		else if (defeated[color][i] != NULL)
			defeated[color][i + 1] = defeated[color][i];
	}
	defeated[color][0] = pion;

}