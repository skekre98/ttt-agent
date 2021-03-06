// Declaration of tic-tac-toe board

#ifndef BOARD_HPP
#define BOARD_HPP

#include "../include/agent.hpp"
#include "../include/human.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Board
{
public:
	vector<vector<int>> board;
	Player *p1;
	Player *p2;
	bool isOver;
	string boardHash;
	int currentPlayer;
	Board();
 	Board(Agent *player1, Agent *player2);
 	Board(Agent *player1, Human *player2);
	Board(Human *player1, Agent *player2);
 	string generateHash();
 	vector<tuple<int,int>> availablePositions();
 	void updateState(tuple<int,int> pos);
 	void isFull();
 	int findWinner();
 	void giveReward();
 	void reset();
 	void showBoard();
 	void agentPlay(int rounds);
	void humanPlay();        
};

#endif /* BOARD_HPP */