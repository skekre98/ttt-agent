// Declaration of Player

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>

using namespace std; 

class Player
{
public:
	string name;
	Player();
 	Player(string name);
 	void feedReward(double reward);
 	tuple<int,int> chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char playerSymbol);        
};

#endif /* PLAYER_HPP */