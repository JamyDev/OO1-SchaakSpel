/*
* Game.h
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#ifndef GAME_H
#define GAME_H

#include "Gameboard.h"
#include "Piece.h"

class Piece;

enum PlayerColor { WHITE, BLACK };

class Game 
{
	public:
		Game();
		~Game();
		void startGame();
		bool isValidMove(Piece* piece, int fromX, int fromY, int toX, int toY);
		Gameboard* getGameboard();

	private:
		Gameboard *gameboard;
		enum PlayerColor activePlayer;

};
#endif
