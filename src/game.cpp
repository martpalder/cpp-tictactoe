#include <iostream>
#include <time.h>
#include "board.hpp"
#include "player.hpp"
#include "cpu.hpp"

unsigned short askChoice();
void announceWinner(unsigned char);

int main() {
	// seed random number generator
	srand(time(0));
	
	// game board
	Board board;
	Board* pBoard = &board;
	
	// player and CPU
	Player player;
	CPU cpu;
	
	// player and CPU characters
	char playerChar = 'X';
	char cpuChar = 'O';
	
	// choices
	unsigned short playerChoice;
	unsigned short cpuChoice;
	
	// checks
	bool legal = false;
	bool filled = false;
	
	// winner
	unsigned char winner;
	
	// draw the board
	pBoard->Draw();
	
	// game loop
	while (1) {
		// ask for next move
		while (1) {
			playerChoice = askChoice();
			legal = player.MakeMove(pBoard, playerChoice, playerChar);
			if (legal) break;
		}
		
		// check for winner and if board is filled
		winner = pBoard->CheckWinner(playerChar, cpuChar);
		filled = pBoard->IsFilled();
		
		// draw the board
		pBoard->Draw();
		
		// if there's a winner or it's filled: break
		if (winner || filled) break;
		
		// randomize CPU move
		while (1) {
			legal = cpu.MakeMove(pBoard, cpuChar);
			if (legal) break;
		}
		
		// check for winner and if board is filled
		winner = pBoard->CheckWinner(playerChar, cpuChar);
		filled = pBoard->IsFilled();
		
		// draw the board
		pBoard->Draw();
		
		// if there's a winner or it's filled: break
		if (winner || filled) break;
	}
	
	// announce winner
	announceWinner(winner);
	
	std::cout << "\nGame over!" << std::endl;
	return 0;
}

unsigned short askChoice()
{
	char charChoice;
	unsigned short choice;
	
	std::cout << "\nEnter a number where you want to move (1-9): ";
	while (1) {
		std::cin >> charChoice;
		choice = static_cast<unsigned short>(charChoice) - '0';
		if (0 < choice < 10) break;
	}
	
	return choice;
}

void announceWinner(unsigned char winner)
{
	if (winner == 1) std::cout << "\nYou win!" << std::endl;
	else if (winner == 2) std::cout << "\nComputer wins!" << std::endl;
	else std::cout << "\nPush" << std::endl;
}