#ifndef GAMEBOARD_H
#define GAMEBOARD_H
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
	
	private:
		Game* game;
		Move* history;
		Piece* defeated[2][16];
		Piece* board[VELDGROOTTE][VELDGROOTTE];
		int historySize;
		void initializeDefeated();
		void addToDefeated(Piece* piece, enum Piece::Color color);
};
#endif
