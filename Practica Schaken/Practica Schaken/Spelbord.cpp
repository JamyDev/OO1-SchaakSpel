#include <iostream>
#include "Spelbord.h"

Spelbord::Spelbord()
{
	initializeBoard();
}

Spelbord::~Spelbord()
{

}

bool Spelbord::canMove(Pion pion, int fromX, int fromY, int toX, int toY)
{
	return false;
}

void printBoard()
{
	std::cout << "";
	std::cout << "---------------------------------";
	std::cout << "| # | % | & | + | W | & | % | # |";
	std::cout << "| ^ | ^ | ^ | ^ | ^ | ^ | ^ | ^ |";
	std::cout << "|   |   |   |   |   |   |   |   |";
	std::cout << "|   |   |   |   |   |   |   |   |";
	std::cout << "|   |   |   |   |   |   |   |   |";
	std::cout << "|   |   |   |   |   |   |   |   |";
	std::cout << "| ^ | ^ | ^ | ^ | ^ | ^ | ^ | ^ |";
	std::cout << "| # | % | & | W | + | & | % | # |";
	std::cout << "---------------------------------";
	std::cout << "";
}

