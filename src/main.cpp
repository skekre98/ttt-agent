#include <iostream>
#include "../include/board.hpp"

using namespace std;

int main() {
	Agent p1 = Agent("Sharvil");
	Human p2 = Human("Sharvil2");
	Board board(p1, p2);
	for (vector<int> row : board.board) {
		for (int i : row) {
			cout << i << "\n";
		}
	}
	return 0;
}