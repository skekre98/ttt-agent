#include <iostream>
#include "../include/board.hpp"
#include "../include/agent.hpp"
#include "../include/human.hpp"

using namespace std;

int main() {
	string train;
	cout << "Would you like to train new TTT agents(y,n) ";
	cin >> train;
	if (train == "Y" || train == "y" || train == "yes") {
		Agent agent1 = Agent("AgentX", 0.3);
		Agent agent2 = Agent("AgentO", 0.3);
		Board board = Board(&agent1, &agent2);
		int rounds;
		cout << "How many rounds would you like to simulate: ";
		cin>>rounds;
		board.agentPlay(rounds);
	} else {
		string symbol;
		cout << "What symbol would you like to play as(X,O) ";
		cin >> symbol;
		bool again = true;
		string play;
		if (symbol == "X" || symbol == "x") {
			Human player1 = Human("HumanX");
			Agent player2 = Agent("AgentO", 0.0);
			player2.loadPolicy("AgentO_policy.txt");
			Board board = Board(&player1, &player2);
			while (again) {
				board.humanPlay();
				again = false;
				cout << "Would you like to play again(y,n) ";
				cin >> play;
				again = play == "Y" || play == "y" ? true : false;
				if (again) {
					board.reset();
					again = true;
				}
			}
		} else {
			Agent player1 = Agent("AgentX", 0.0);
			Human player2 = Human("HumanO");
			player1.loadPolicy("AgentX_policy.txt");
			Board board = Board(&player1, &player2);
			while (again) {
				board.humanPlay();
				again = false;
				cout << "Would you like to play again(y,n) ";
				cin >> play;
				again = play == "Y" || play == "y" ? true : false;
				if (again) {
					board.reset();
					again = true;
				}
			}
		}
	}

	return 0;
}