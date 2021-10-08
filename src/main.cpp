#include <iostream>
#include "../include/board.hpp"

int main() {
	Board board;
	board.setBoard(1,-1);
	std::cout << board.m << "\n";
	std::cout << board.n << "\n";
	return 0;
}