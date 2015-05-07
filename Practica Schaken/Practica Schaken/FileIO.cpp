#include "FileIO.h"
#include "Game.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <string.h>

/*
||W||
|BR|BH|BB|BK|BQ|BB|BH|BR|
|BP|BP|BP|BP|BP|BP|BP|BP|
|  |  |  |  |  |  |  |  |
|  |  |  |  |  |  |  |  |
|  |  |  |  |  |  |  |  |
|  |  |  |  |  |  |  |  |
|WP|WP|WP|WP|WP|WP|WP|WP|
|WR|WH|WB|WK|WQ|WB|WH|WR|

*/
void FileIO::putToFile(Game& game)
{
	ofstream file("game.txt");

	if (!file)
		return;
	//0 = WHITE in PlayerColor
	if (game.getActivePlayer() == 0)
		file.write("||W||\n", 6);
	else
		file.write("||B||\n", 6);
	file.put('|');

	for (int i = 0; i < Gameboard::VELDGROOTTE; ++i)
	{
		for (int j = 0; j < Gameboard::VELDGROOTTE; ++j)
		{
			if (game.getGameboard()->getPieceAt(i, j)->getColor() == Piece::Color::WHITE)
				file.put('W');
			else
				file.put('B');
			if (game.getGameboard()->getPieceAt(i, j)->getType() == Piece::Type::ROOK)
				file.put('R');
			else if (game.getGameboard()->getPieceAt(i, j)->getType() == Piece::Type::PAWN)
				file.put('P');
			else if (game.getGameboard()->getPieceAt(i, j)->getType() == Piece::Type::BISHOP)
				file.put('B');
			else if (game.getGameboard()->getPieceAt(i, j)->getType() == Piece::Type::KNIGHT)
				file.put('H');
			else if (game.getGameboard()->getPieceAt(i, j)->getType() == Piece::Type::QUEEN)
				file.put('Q');
			else if (game.getGameboard()->getPieceAt(i, j)->getType() == Piece::Type::KING)
				file.put('K');
			file.put('|');
		}
		file.put('\n');
	}
	file.close();
}

void FileIO::getBoardFromFile(Gameboard* gameboard)
{
	char ch;
	int x = -1, y = 0;
	bool first = true;
	Piece::Color color = Piece::WHITE;
	ifstream file("game.txt");

	if (!file)
		return;
	
	while ((ch = file.get()) != EOF && ch != '\n')
		;
	while ((ch = file.get() != EOF))
	{
		if (ch == '|')
		{
			x++;
			first = true;
			ch = file.get();
		}
		if (ch == ' ' && first)
		{
			first = false;
			gameboard->putPiece(NULL, x, y);
			file.get();
		}
		if (ch == 'B' && first)
		{
			first = false;
			color = Piece::BLACK;
		}
		else if (ch == 'W' && first)
		{
			first = false;
			color = Piece::WHITE;
		}
		switch (ch = file.get() && !first)
		{
		case 'R':
			Rook* piece = new Rook(color);
			gameboard->putPiece(piece, x, y);
			break;
		case 'B':
			Bishop* piece = new Bishop(color);
			gameboard->putPiece(piece, x, y);
			break;
		case 'H':
			Knight* piece = new Knight(color);
			gameboard->putPiece(piece, x, y);
			break;
		case 'K':
			King* piece = new King(color);
			gameboard->putPiece(piece, x, y);
			break;
		case 'Q':
			Queen* piece = new Queen(color);
			gameboard->putPiece(piece, x, y);
			break;
		case 'P':
			Pawn* piece = new Pawn(color);
			gameboard->putPiece(piece, x, y);
			break;
		default:
			break;
		}
		if (ch == '\n')
		{
			x = 0;
			y++;
		}
	}
	file.close();
}

int FileIO::getActivePlayer()
{
	char ch;
	ifstream file("game.txt");
	if (!file)
		return -1;

	while ((ch = file.get()) == '|')
		;
	if (ch == 'W')
	{
		file.close();
		return 0;
	}
	else
	{
		file.close();
		return 1;
	}


}