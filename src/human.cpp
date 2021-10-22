// Implementation of Human class
#include "../include/human.hpp"
#include <map> 

Human::Human()
{
	name = "Test Human";
}

Human::Human(string input_name)
{
	name = input_name;
}

void Human::feedReward(double reward){}

void Human::addState(string state){}

void printBoard(vector<vector<int>> currentBoard)
{
	map<int, string> ttt_map {
		{1, "X"},
		{-1, "O"},
		{0, " "},
	};
	int count = 0;
	for (vector<int> row : currentBoard) {
		cout << "-------" << endl;
		for (int cell : row) {
			string space = ttt_map[cell];
			cout << "|" << space;
		}
		cout << "| " << ++count << endl;
	}
	cout << "-------" << endl;
	cout << " 1 2 3" << endl;	
}

tuple<int,int> Human::chooseAction(vector<tuple<int,int>> positions, vector<vector<int>> currentBoard, char HumanSymbol)
{
	tuple<int, int> move;
	int row;
	int col;
	while (true) {
		printBoard(currentBoard);
		cout << "Row: ";
		cin >> row;
		cout << "Column: ";
		cin >> col;
		move = tuple<int,int>(row-1,col-1);
		for (tuple<int, int> freeSpace : positions) {
			if (freeSpace == move) {
				return move;
			}
		}
		cout << "Invalid move, try again..." << endl;
	}
}

void Human::reset()
{
	cout << "game has been reset\n" << endl;
}