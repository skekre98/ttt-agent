# TTT Agent

This is an implementation of a multiagent value iteration algorithm for playing Tic Tac Toe.

## Primer

The problem can be formulated into a Markov Decision Process (MDP) in which we assess elements such as 
environment, state, action, and value. The implementation leverages a dynamic programming algorithm called
[value iteration](https://web.mit.edu/dimitrib/www/Multiagent_VI.pdf) to find the optimal action for any
state in the tic-tac-toe environment.

## Gameplay

The following are guidelines on how to train reinforcement learning agents as well as how you can play your 
trained agents.

### Building

The program executable can be built by using the [cmake](https://cmake.org/) build tool.

```bash
$ cmake .
$ make
$ ./ttt-agent
```

### Training

You will be able to specify the experiment rate as well as the number of games to simulate during 
training. The experiment rate is used to randomly select an action during the training process in 
order to alleviate overfitting issues.

```bash
$ ./ttt-agent
Would you like to train new TTT agents(y,n) y
Input experiment rate: 0.3
How many rounds would you like to simulate: 10000
-------
| |O|X|
-------
| |X| |
-------
|X| |O|
-------
55% [=====>     ] 5510 rnds
Duration: 0m37s
148.92 Rnds/sec
```

### Human Player

There is also an option to play against the recently trained agent.

```bash
$ ./ttt-agent
Would you like to train new TTT agents(y,n) n
What symbol would you like to play as(X,O) O
-------
| | | | 1
-------
| | | | 2
-------
| | |X| 3
-------
 1 2 3
Row: 2
Column: 2
-------
| | | | 1
-------
| |O| | 2
-------
| |X|X| 3
-------
 1 2 3
Row: 
```