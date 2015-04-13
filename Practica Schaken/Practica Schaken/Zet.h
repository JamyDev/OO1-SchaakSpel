/*
* Zet.h
* Authors: Jeroen Ceyssens
*/

#ifndef ZET_H
#define ZET_H
#include "Pion.h"

class Spelbord;
class Zet
{
	public:
		//default constructor
		Zet();
		//param constructor
		Zet(Pion* usedPion, int fromX, int fromY, int toX, int toY);
		//booleans that check which moves the pions can do
		static bool canHorseMove(int fromX, int fromY, int toX, int toY);
		static bool canSoldMove(int fromX, int fromY, int toX, int toY, bool isFirst, enum Pion::Color color);
		static bool canSoldAttack(int fromX, int fromY, int toX, int toY, enum Pion::Color color);
		static bool canCastleMove(int fromX, int fromY, int toX, int toY);
		static bool canBissMove(int fromX, int fromY, int toX, int toY);
		static bool canQueenMove(int fromX, int fromY, int toX, int toY);
		static bool canKingMove(int fromX, int fromY, int toX, int toY);

	private:
		Pion *pion;
		int originalX;
		int originalY;
		int newX;
		int newY;
};
#endif
