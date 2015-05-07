/*
 * Gameboard.cpp
 * Authors: Jamy Timmermans, Jeroen Ceyssens
 */

#include <iostream>
#include "Gameboard.h"
#include "Game.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Piece.h"

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

bool Gameboard::isPieceAt(int x, int y) 
{
	if (x < Gameboard::VELDGROOTTE && y < Gameboard::VELDGROOTTE)
	{
		if (board[y][x] == NULL)
			return false;
		else
			return true;
	}
	return false;
}


Piece* Gameboard::getPieceAt(int x, int y)
{
	if (x < Gameboard::VELDGROOTTE && y < Gameboard::VELDGROOTTE)
	{
		return board[y][x];
	}
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
        board[6][i] = new Pawn(Piece::Color::BLACK);
		board[6][i]->setNewPos(i, 6);
		board[1][i] = new Pawn(Piece::Color::WHITE);
		board[1][i]->setNewPos(i, 1);
    }
    // Put Rooks
    board[7][0] = new Rook(Piece::Color::BLACK);
	board[7][0]->setNewPos(0, 7);
    board[7][7] = new Rook(Piece::Color::BLACK);
	board[7][7]->setNewPos(7, 7);
    board[0][0] = new Rook(Piece::Color::WHITE);
	board[0][0]->setNewPos(0, 0);
    board[0][7] = new Rook(Piece::Color::WHITE);
	board[0][7]->setNewPos(7, 0);

    // Put Knights
    board[7][1] = new Knight(Piece::Color::BLACK);
	board[7][1]->setNewPos(1, 7);
    board[7][6] = new Knight(Piece::Color::BLACK);
	board[7][6]->setNewPos(6, 7);
    board[0][1] = new Knight(Piece::Color::WHITE);
	board[0][1]->setNewPos(1, 0);
    board[0][6] = new Knight(Piece::Color::WHITE);
	board[0][6]->setNewPos(6, 0);
    
    // Put Bischops
    board[7][2] = new Bishop(Piece::Color::BLACK);
	board[7][2]->setNewPos(2, 7);
    board[7][5] = new Bishop(Piece::Color::BLACK);
	board[7][5]->setNewPos(5, 7);
    board[0][2] = new Bishop(Piece::Color::WHITE);
	board[0][2]->setNewPos(2, 0);
    board[0][5] = new Bishop(Piece::Color::WHITE);
	board[0][5]->setNewPos(5, 0);

    // King and Queen
    board[7][3] = new King(Piece::Color::BLACK);
	board[7][3]->setNewPos(3, 7);
    board[0][4] = new King(Piece::Color::WHITE);
	board[0][4]->setNewPos(4, 0);
    board[7][4] = new Queen(Piece::Color::BLACK);
	board[7][4]->setNewPos(4, 7);
    board[0][3] = new Queen(Piece::Color::WHITE);
	board[0][3]->setNewPos(3, 0);
}

bool Gameboard::move(Piece* piece, Move& move)
{
	bool valid = false;
	valid = piece->isValidMove(move, *game);
	if (valid)
	{
		if (board[move.getToY()][move.getToX()] == NULL)
		{
			board[move.getToY()][move.getToX()] = piece;
			
		}
		else if (board[move.getToY()][move.getToX()]->getColor() != piece->getColor())
		{
			addToDefeated(*board[move.getToY()][move.getToX()], board[move.getToY()][move.getToX()]->getColor());
			board[move.getToY()][move.getToX()] = piece;

		}
		piece->setNewPos(move.getToX(), move.getToY());
		// TODO: Vragen of dit wel kan
		history = new Move[historySize + 1];
		history[historySize] = move;
		board[move.getFromY()][move.getFromX()] = NULL;
		historySize++;
		return true;
	}
	else
		return false;
	
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
void Gameboard::addToDefeated(Piece& piece, enum Piece::Color color)
{
	for (int i = VELDGROOTTE * 2 - 1; i >= 0; --i)
	{
		if (defeated[color][i] != NULL && i != VELDGROOTTE * 2 - 1)
			return;
		else if (defeated[color][i] != NULL)
			defeated[color][i + 1] = defeated[color][i];
	}
	defeated[color][0] = &piece;

}