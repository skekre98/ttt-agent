// Declaration of Agent

#ifndef AGENT_HPP
#define AGENT_HPP

#include "../include/player.hpp"
#include "../include/board.hpp"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Agent: public Player
{
public:
	string name;
	double l_rate;
	double decay_gamma;
	double exp_rate;
	vector<string> states;
	map<string, double> state_values;
 	Agent(string name);
 	string getHash(Board board);
 	void addState(string state);
 	tuple<int,int> chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char playerSymbol);
 	void feedReward(double reward);        
};

#endif /* AGENT_HPP */