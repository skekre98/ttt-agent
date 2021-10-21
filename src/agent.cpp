// Implementation of Agent class
#include "../include/agent.hpp"
#include "../include/board.hpp"
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <sstream> 


Agent::Agent()
{
	name = "Test Agent";
	l_rate = 0.2;
	decay_gamma = 0.9;
	exp_rate = 0.3;
}

Agent::Agent(string input_name)
{
	name = input_name;
	l_rate = 0.2;
	decay_gamma = 0.9;
	exp_rate = 0.3;
}

void Agent::addState(string state)
{
	states.push_back(state);
}

void Agent::showStateValues()
{
	for(const auto &[state, vs]  : state_values) {
	    cout << "State: " << state << ", " << "V(S): " << vs << endl;
	}	
}

// Function for selection actions based on reinforced states 
tuple<int,int> Agent::chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char playerSymbol) 
{
	tuple<int, int> action;
	if ((double)rand()/RAND_MAX <= exp_rate) {
		int r_idx = rand() % positions.size();
		action = positions[r_idx]; 
	} else {
		double max_value = -999.0;
		for (tuple<int,int> p : positions) {
			Board newBoard;
			newBoard.board = currentBoard;
			newBoard.board[get<0>(p)][get<1>(p)] = playerSymbol;
			string newBoardHash = newBoard.generateHash();
			double value = state_values.find(newBoardHash) == state_values.end() ? 0.0 : state_values.at(newBoardHash);
			if (value >= max_value) {
				max_value = value;
				action = p;
			}
		}

	}

	return action;
}

// backpropagate and update state values depending on reward 
void Agent::feedReward(double reward)
{
	for (int i = states.size()-1; i >= 0; i--) {
		string state = states[i];
		if (state_values.find(state) == state_values.end()) {
			state_values[state] = l_rate * decay_gamma * reward;
		} else {
			state_values[state] += l_rate * (decay_gamma * reward - state_values[state]);
		}
		reward = state_values[state];
	}
}

void Agent::reset()
{
	states.clear();
}

void Agent::savePolicy()
{
	string fname = name + "_policy.txt";
	fstream newfile;
	newfile.open(fname,ios::out);
    map<string, double>::iterator it = state_values.begin();
    while (it != state_values.end()) {
    	string line = it->first + "=" + to_string(it->second)+"\n";
        newfile << line;
        it++;
    }

    newfile.close();
}

void Agent::loadPolicy(string fname)
{
	fstream policyFile;
	policyFile.open(fname,ios::in);
	state_values.clear();
	string pair;
	while (getline(policyFile, pair)) {
		replace(pair.begin(), pair.end(), '=', ' ');
		stringstream ss(pair);
		string state;
		ss >> state;
		double score;
		ss >> score;
		state_values[state] = score;
	}

	policyFile.close();
}








