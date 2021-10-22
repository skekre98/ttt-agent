#include <iostream>
#include "../include/board.hpp"
#include "../include/agent.hpp"
#include "../include/human.hpp"

using namespace std;

int main() {
	string train;
	cout << "Would you like to train new TTT agents(y,n) ";
	cin>>train;
	if (train == "Y" || train == "y" || train == "yes") {
		Agent agent1 = Agent("AgentX");
		Agent agent2 = Agent("AgentO");
		Board board = Board(&agent1, &agent2);
		int rounds;
		cout << "How many rounds would you like to simulate: ";
		cin>>rounds;
		board.agentPlay(rounds);

		// Agent testAgent;
		// testAgent.loadPolicy("AgentO_policy.txt");
		// testAgent.showStateValues();
	}

	return 0;
}