/*
* Gameboard.h
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Move.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

class Game;
class Piece;

class Gameboard 
{
	public:
		Gameboard(Game* game1);
		~Gameboard();
		const static int VELDGROOTTE = 8;
		void clearBoard();
		bool move(Piece* piece, Move& move);
		bool isPieceAt(int x, int y);
		Piece* getPieceAt(int x, int y);
		void putPiece(Piece* piece, int x, int y);
		bool promote(Piece* piece, char type);
		
	private:
		Game* game;
		Piece* board[VELDGROOTTE][VELDGROOTTE];
		Piece* defeated[2][16];
		void resetBoard();
		void initializeBoard();
		void initializeDefeated();
		void addToDefeated(Piece& piece, enum Piece::Color color);
};
#endif
