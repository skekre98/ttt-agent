// Implementation to tic-tac-toe board
#include "../include/board.hpp"
#include <tuple>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <map>


Board::Board()
{
	board = {
		{0,0,0}, 
		{0,0,0}, 
		{0,0,0}
	};
}

// constructor with two agents 
Board::Board(Agent *player1, Agent *player2) : p1(player1), p2(player2)
{
	board = {
		{0,0,0}, 
		{0,0,0}, 
		{0,0,0}
	};
	isOver = false;
	currentPlayer = 1;
}

// constructor with human player1
Board::Board(Human *player1, Agent *player2) : p1(player1), p2(player2)
{
	board = {
		{0,0,0}, 
		{0,0,0}, 
		{0,0,0}
	};
	isOver = false;
	currentPlayer = 1;
}

// constructor with human player2
Board::Board(Agent *player1, Human *player2) : p1(player1), p2(player2)
{
	board = {
		{0,0,0}, 
		{0,0,0}, 
		{0,0,0}
	};
	isOver = false;
	currentPlayer = 1;
}

// create unique hash from current board state 
string Board::generateHash()
{
	string hash;
	for (vector<int> row : board){
		for (int cell : row) {
			hash.append(to_string(cell));
		}
	}

	boardHash = hash;
	return hash;
}

// returns available positions on board
vector<tuple<int,int>> Board::availablePositions()
{
	vector<tuple<int,int>> positions;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 0) {
				tuple<int,int> pos(i, j);
				positions.push_back(pos);
			}
		}
	}

	return positions;
}

// updates board state for current player
void Board::updateState(tuple<int,int> pos)
{
	board[get<0>(pos)][get<1>(pos)] = currentPlayer;
	currentPlayer = currentPlayer == 1 ? -1 : 1;
}

// checks if the board is full 
void Board::isFull()
{
	int count = 0;
	for (vector<int> row : board) {
		for (int cell : row) {
			if (cell == 0) {
				count++;
			}
		}
	}

	isOver = count == 0 ? true : false;
}

// checks board state to see if either player has won 
int Board::findWinner()
{	
	// check the rows to see if there is a winner 
	int row_sum;
	for (vector<int> row : board){
		row_sum = accumulate(row.begin(), row.end(), 0);
		if (row_sum == 3){
			isOver = true;
			return 1;
		} else if (row_sum == -3){
			isOver = true;
			return -1;
		}
	}

	// check columns to see if there is a winner 
	int col_sum;
	for (int i = 0; i < 3; i++){
		col_sum = 0;
		for (int j = 0; j < 3; j++){
			col_sum += board[j][i];
		}
		if (col_sum == 3){
			isOver = true;
			return 1;
		} else if (col_sum == -3){
			isOver = true;
			return -1;
		}
	}

	// check diagonals for winner 
	int diag1 = 0;
	int diag2 = 0;
	for (int i = 0; i < 3; i++){
		diag1 += board[i][i];
		diag2 += board[i][2-i];
	}

	int diagSum = max(abs(diag1), abs(diag2));
	if (diagSum == 3){
		isOver = true;
		if (diag1 == 3 || diag2 == 3){
			isOver = true;
			return 1;
		} else {
			isOver = true;
			return -1;
		}
	}

	isOver = false;
	return 0;
}

// notify player with reward when game ends 
void Board::giveReward()
{
	int result = findWinner();
	if (result == 1){
		p1->feedReward(1.0);
		p2->feedReward(0.0);
	} else if (result == -1){
		p1->feedReward(0.0);
		p2->feedReward(1.0);
	} else {
		p1->feedReward(0.1);
		p2->feedReward(0.5);
	}
}

void Board::reset()
{
	giveReward();
	p1->reset();
	p2->reset();
	board = {
		{0,0,0}, 
		{0,0,0}, 
		{0,0,0}
	};
	isOver = false;
	currentPlayer = 1;
}

void Board::showBoard()
{
	map<int, string> ttt_map {
		{1, "X"},
		{-1, "O"},
		{0, " "},
	};
	for (vector<int> row : board) {
		cout << "-------" << endl;
		for (int cell : row) {
			string space = ttt_map[cell];
			cout << "|" << space;
		}
		cout << "|\n";
	}
	cout << "-------" << endl;
}

void Board::agentPlay(int rounds)
{
	for (int i = 1; i <= rounds; i++) {
		if (i % 1000 == 0){
			cout << "Round " << i << "\n";
		}

		int win;
		tuple<int,int> action;
		vector<tuple<int,int>> positions;
		while (!isOver) {
			positions = availablePositions();
			action = p1->chooseAction(positions, board, currentPlayer);
			updateState(action);
			generateHash();
			p1->addState(boardHash);
			win = findWinner();
			isFull();
			if (win != 0) {
				break;
			} else if (isOver){
				break;
			} else {
				positions = availablePositions();
				action = p2->chooseAction(positions, board, currentPlayer);
				updateState(action);
				generateHash();
				p2->addState(boardHash);
				win = findWinner();
				if (win != 0) {
					break;
				}
			}
		}
		showBoard();
		reset();
	}

	string save;
	cout << "Would you like to save agent policy values(y,n) ";
	cin>>save;
	if (save == "Y" || save == "y" || save == "yes") {
		p1->savePolicy();
		p2->savePolicy();
	} else {
		p1->showStateValues();
		p2->showStateValues();
	}
}

void Board::humanPlay()
{
	int win;
	tuple<int,int> action;
	vector<tuple<int,int>> positions;
	while (!isOver) {
		positions = availablePositions();
		action = p1->chooseAction(positions, board, currentPlayer);
		updateState(action);
		generateHash();
		p1->addState(boardHash);
		win = findWinner();
		isFull();
		if (win != 0) {
			break;
		} else if (isOver){
			break;
		} else {
			positions = availablePositions();
			action = p2->chooseAction(positions, board, currentPlayer);
			updateState(action);
			generateHash();
			p2->addState(boardHash);
			win = findWinner();
			if (win != 0) {
				break;
			}
		}
	}

	int result = findWinner();
	showBoard();
	switch (result) {
		case 1:
			cout << "Player X won!" << endl;
			break;
		case -1:
			cout << "Player O won!" << endl;
			break;
		default:
			cout << "Game ended in a tie..." << endl;
	}
}
