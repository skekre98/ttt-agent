// Declaration of Human

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "../include/player.hpp"
#include <iostream>

using namespace std;

class Human: public Player
{
public:
	Human();
 	Human(string name);
};

#endif /* HUMAN_HPP */