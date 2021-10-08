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