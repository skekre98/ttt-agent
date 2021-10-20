// Declaration of tic-tac-toe board

#ifndef BOARD_HPP
#define BOARD_HPP

#include "../include/player.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Board
{
public:
	vector<vector<int>> board;
	Player p1;
	Player p2;
	bool isOver;
	string boardHash;
	int currentPlayer;
	Board();
 	Board(Player player1, Player player2);
 	string generateHash();
 	vector<tuple<int,int>> availablePositions();
 	void updateState(tuple<int,int> pos);
 	int findWinner();
 	void giveReward();
 	void reset();
 	void agentPlay(int rounds);        
};

#endif /* BOARD_HPP */