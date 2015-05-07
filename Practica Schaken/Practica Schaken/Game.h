/*
* Game.h
* Authors: Jamy Timmermans, Jeroen Ceyssens
*/

#ifndef GAME_H
#define GAME_H
#include "Piece.h"
#include "Gameboard.h"
#include "Move.h"
#include "UI.h"

class Piece;
class Gameboard;

class Game 
{
	public:
		static const enum PlayerColor {WHITE, BLACK};
		Game();
		~Game();
		void startGame();
		Gameboard* getGameboard();
		enum PlayerColor getActivePlayer() { return activePlayer; };
	private:
		Gameboard *gameboard;
		UI ui;
		enum PlayerColor activePlayer;

};
#endif
