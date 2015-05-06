/*
* Gameboard.h
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Piece.h"
#include "Move.h"

class Game;

class Gameboard 
{
	public:
		Gameboard(Game* game1);
		~Gameboard();
		const static int VELDGROOTTE = 8;
		void initializeBoard();
		bool move(Piece* piece, Move& move);
		void printBoard();
		Piece* getPieceAt(int x, int y);
	private:
		Game* game;
		Move* history;
		Piece* board[VELDGROOTTE][VELDGROOTTE];
		Piece* defeated[2][16];
		int historySize;
		void initializeDefeated();
		void addToDefeated(Piece* piece, enum Piece::Color color);
};
#endif
