/*
* Gameboard.h
* Authors: Jamy Timmermans
*/

#ifndef SPELBORD_H
#define SPELBORD_H
#include "Piece.h"
#include "Move.h"

const int VELDGROOTTE = 8;

class Game;

class Gameboard 
{
	public:
		Gameboard(Game* game1);
		~Gameboard();
		void initializeBoard();
		bool canMove(Piece* piece, int fromX, int fromY, int toX, int toY);
		bool move(Piece* piece, int fromX, int fromY, int toX, int toY);
		void printBoard();
		Piece* board[VELDGROOTTE][VELDGROOTTE];
	private:
		Game* game;
		Move* history;
		Piece* defeated[2][16];
		int historySize;
		void initializeDefeated();
		void addToDefeated(Piece* piece, enum Piece::Color color);
};
#endif
