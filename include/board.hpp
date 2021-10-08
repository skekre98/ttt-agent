// Declaration of tic-tac-toe board
#include "../include/agent.hpp"
#include "../include/human.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Board
{
public:
	vector<vector<int>> board;
	bool isOver;
	string boardHash;
	int currentPlayer;
 	Board(Player, Player);        
};