// Implementation of Player class
#include "../include/player.hpp"

Player::Player(){} 

Player::Player(string input_name)
{
	name = input_name;	
}

void Player::feedReward(double reward)
{
	cout << "player reward given\n";
}

void Player::addState(string state)
{
	cout << "adding state to player\n";
}

void Player::showStateValues()
{
	cout << "player state values" << endl;
}

tuple<int,int> Player::chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char playerSymbol)
{
	return tuple<int,int>(0,1);
}

void Player::reset()
{
	cout << "player reset\n";
}

void Player::savePolicy()
{
	cout << "saving player policy\n";
}