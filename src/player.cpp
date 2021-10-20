// Implementation of Player class
#include "../include/player.hpp"

Player::Player(){} 

Player::Player(string input_name)
{
	name = input_name;	
}

void Player::feedReward(double reward)
{
	cout << "reward given\n";
}

tuple<int,int> Player::chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char playerSymbol)
{
	return tuple<int,int>(0,0);
}