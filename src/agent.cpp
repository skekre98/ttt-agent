// Implementation of Agent class
#include "../include/agent.hpp" 

Agent::Agent(string input_name)
{
	name = input_name;
	l_rate = 0.2;
	decay_gamma = 0.9;
	exp_rate = 0.0;
}
