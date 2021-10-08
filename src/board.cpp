// Implementation to tic-tac-toe board
#include "../include/board.hpp" 

Board::Board(Player player1, Player player2)
{
	board = {
		{0,0,0}, 
		{0,0,0}, 
		{0,0,0}
	};
	Player p1 = player1;
	Player p2 = player2;
	isOver = false;
	currentPlayer = 1;
}