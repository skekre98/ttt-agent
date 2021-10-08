// Declaration of Agent
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
 	Agent(string name);        
};