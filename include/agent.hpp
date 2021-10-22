// Declaration of Agent

#ifndef AGENT_HPP
#define AGENT_HPP

#include "../include/player.hpp"
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
	Agent();
 	Agent(string name, double er);
 	void addState(string state) override;
 	void showStateValues() override;
 	tuple<int,int> chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char playerSymbol) override;
 	void feedReward(double reward) override; 
 	void reset() override;
 	void savePolicy() override;
 	void loadPolicy(string fname);       
};

#endif /* AGENT_HPP */