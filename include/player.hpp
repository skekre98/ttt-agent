// Declaration of Player

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

using namespace std; 

class Player
{
public:
	string name;
	Player();
 	Player(string name);
 	void feedReward(double reward);        
};

#endif /* PLAYER_HPP */