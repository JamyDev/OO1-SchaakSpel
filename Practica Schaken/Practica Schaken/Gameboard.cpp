/*
 * Gameboard.cpp
 * Authors: Jamy Timmermans, Jeroen Ceyssens
 */

#include <iostream>
#include "Gameboard.h"
#include "Game.h"

Gameboard::Gameboard(Game* spel1)
{
	game = spel1;
	initializeBoard();
	initializeDefeated();
	historySize = 0;
}

Gameboard::~Gameboard()
{
	// TODO: delete all Pionnen en ander geheugen
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
        board[6][i] = new Piece(Piece::Color::BLACK, Piece::Type::PAWN);
        board[1][i] = new Piece(Piece::Color::WHITE, Piece::Type::PAWN);
    }
    // Put Towers
    board[7][0] = new Piece(Piece::Color::BLACK, Piece::Type::ROOK);
    board[7][7] = new Piece(Piece::Color::BLACK, Piece::Type::ROOK);
    board[0][0] = new Piece(Piece::Color::WHITE, Piece::Type::ROOK);
    board[0][7] = new Piece(Piece::Color::WHITE, Piece::Type::ROOK);

    // Put Horses
    board[7][1] = new Piece(Piece::Color::BLACK, Piece::Type::KNIGHT);
    board[7][6] = new Piece(Piece::Color::BLACK, Piece::Type::KNIGHT);
    board[0][1] = new Piece(Piece::Color::WHITE, Piece::Type::KNIGHT);
    board[0][6] = new Piece(Piece::Color::WHITE, Piece::Type::KNIGHT);
    
    // Put Bischops
    board[7][2] = new Piece(Piece::Color::BLACK, Piece::Type::BISHOP);
    board[7][5] = new Piece(Piece::Color::BLACK, Piece::Type::BISHOP);
    board[0][2] = new Piece(Piece::Color::WHITE, Piece::Type::BISHOP);
    board[0][5] = new Piece(Piece::Color::WHITE, Piece::Type::BISHOP);

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
	valid &= game->isValidMove(piece, fromX, fromY, toX, toY);
	if (valid)
	{
		if (board[toY][toX] == NULL)
			board[toY][toX] = piece;
		else if (board[toY][toX]->getColor() != piece->getColor())
		{
			addToDefeated(board[toY][toX], board[toY][toX]->getColor());
			board[toY][toX] = piece;

		}
		// TODO: Vragen of dit wel kan
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
		case Piece::Type::PAWN:
			bool first = false, valid = false;
			first = (piece->getColor() == Piece::Color::WHITE && fromY == 1) ||
					(piece->getColor() == Piece::Color::BLACK && fromY == 6);	

			valid = Move::canPawnMove(fromX, fromY, toX, toY, first, piece->getColor());
			valid |= Move::canPawnAttack(fromX, fromY, toX, toY, piece->getColor());

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
void Gameboard::addToDefeated(Piece* piece, enum Piece::Color color)
{
	for (int i = VELDGROOTTE * 2 - 1; i >= 0; --i)
	{
		if (defeated[color][i] != NULL && i != VELDGROOTTE * 2 - 1)
			return;
		else if (defeated[color][i] != NULL)
			defeated[color][i + 1] = defeated[color][i];
	}
	defeated[color][0] = piece;

}