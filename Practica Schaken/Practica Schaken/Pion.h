class Pion
{
private:
	enum Color color;
	enum Type type;
public:
	//Defines which color the pion has.
	enum Color { BLACK, WHITE };
	//A pion can be any of the following types, possible moves and rules are based on these types.
	enum Type { SOLDIER, HORSE, CASTLE, BISCHOP, QUEEN, KING };
	
	/*Zoals ik het nu zie moeten de verplaatsingen gedaan worden in de class Spelbord.
	**In de class Zet kan het type opgevraagd worden van de pion om zo te weten welke moves mogelijk moeten zijn.
	**De struct Location kunnen we steeds naar verwijzen zodra we verplaatsingen uitvoeren.
	**Voor de rest wat nodig is ga ik nog met je moeten bespreken.
	*/

};