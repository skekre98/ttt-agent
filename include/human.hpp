// Declaration of Human

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "../include/player.hpp"
#include <iostream>

using namespace std;

class Human: public Player
{
public:
	Human();
 	Human(string name);
	void addState(string state) override;
	tuple<int,int> chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char playerSymbol) override;
 	void feedReward(double reward) override;
	void reset() override;
};

#endif /* HUMAN_HPP */