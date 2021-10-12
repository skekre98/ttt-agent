// Implementation of Agent class
#include "../include/agent.hpp"
#include <time.h>
#include <cstdlib> 

Agent::Agent(string input_name)
{
	name = input_name;
	l_rate = 0.2;
	decay_gamma = 0.9;
	exp_rate = 0.3;
}

string Agent::getHash(Board board)
{
	string boardHash = board.generateHash();
	return boardHash;
}

void Agent::addState(string state)
{
	states.push_back(state);
}

tuple<int,int> Agent::chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char playerSymbol) 
{
	srand((unsigned)time(NULL));
	double draw = (double)rand()/RAND_MAX;
	tuple<int, int> action;
	if (draw <= exp_rate) {
		int r_idx = rand() % positions.size();
		action = positions[r_idx]; 
	} else {
		double max_value = -999.0;
		for (tuple<int,int> p : positions) {
			Board newBoard;
			newBoard.board = currentBoard;
			newBoard.board[get<0>(p)][get<1>(p)] = playerSymbol;
			string newBoardHash = getHash(newBoard);
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
		reward = state_values[state]
	}
}












