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
	virtual void addState(string state);
	virtual void showStateValues();
 	virtual void feedReward(double reward);
 	virtual tuple<int,int> chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char playerSymbol);
	virtual void reset();
 	virtual void savePolicy();        
};

#endif /* PLAYER_HPP */