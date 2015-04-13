#ifndef ZET_H
#define ZET_H
class Spelbord;
class Pion;
class Zet
{
	public:
		void moveTo(Spelbord &spelbord, Pion &pion, int toX, int toY);
		//booleans that check which moves the pions can do
		bool canHorseMove(int fromX, int fromY, int toX, int toY);
		bool canSoldMove(int fromX, int fromY, int toX, int toY);
		bool canCastleMove(int fromX, int fromY, int toX, int toY);
		bool canBissMove(int fromX, int fromY, int toX, int toY);
		bool canQueenMove(int fromX, int fromY, int toX, int toY);
		bool canKingMove(int fromX, int fromY, int toX, int toY);

	private:
		
};
#endif
