#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board {
	static const unsigned char ROWS = 3;
	static const unsigned char COLUMNS = 3;

public:
	char squares[ROWS][COLUMNS];
	
	Board()
	{
		for (unsigned char i = 0; i < ROWS; ++i) {
			for (unsigned char j = 0; j < COLUMNS; ++j) {
				squares[i][j] = ' ';
			}
		}
	}
	
	void Draw()
	{
		std::cout << '\n';
		for (unsigned char i = 0; i < ROWS; ++i) {
			std::cout << "\t ";
			for (unsigned char j = 0; j < COLUMNS; ++j) {
				if (j == 0) std::cout << ' ';
				std::cout << squares[i][j];
				if (j < COLUMNS - 1) std::cout << " | ";
			}
			if (i < ROWS - 1) {
				std::cout << "\n\t ";
				for (unsigned char k = 0; k < COLUMNS; ++k) {
					std::cout << "---";
				}
				std::cout << "--\n";
			}
		}
		std::cout << '\n';
	}
	
	unsigned char CheckWinner(char player, char cpu)
	{
		unsigned char winner;
		// player  checks
		if ((squares[0][0] == player && squares[1][0] == player && squares[2][0] == player)
			|| (squares[0][0] == player && squares[0][1] == player && squares[0][2] == player)) winner = 1;
		else if ((squares[0][1] == player && squares[1][1] == player && squares[2][1] == player)
			|| (squares[1][0] == player && squares[1][1] == player && squares[1][2] == player)) winner = 1;
		else if ((squares[0][2] == player && squares[1][2] == player && squares[2][2] == player)
			|| (squares[2][0] == player && squares[2][1] == player && squares[2][2] == player)) winner = 1;
		else if ((squares[0][0] == player && squares[1][1] == player && squares[2][2] == player)
			|| (squares[2][0] == player && squares[1][1] == player && squares[0][2] == player)) winner = 1;
		// CPU  checks
		else if ((squares[0][0] == cpu && squares[1][0] == cpu && squares[2][0] == cpu)
			|| (squares[0][0] == cpu && squares[0][1] == cpu && squares[0][2] == cpu)) winner = 2;
		else if ((squares[0][1] == cpu && squares[1][1] == cpu && squares[2][1] == cpu)
			|| (squares[1][0] == cpu && squares[1][1] == cpu && squares[1][2] == cpu)) winner = 2;
		else if ((squares[0][2] == cpu && squares[1][2] == cpu && squares[2][2] == cpu)
			|| (squares[2][0] == cpu && squares[2][1] == cpu && squares[2][2] == cpu)) winner = 2;
		else if ((squares[0][0] == cpu && squares[1][1] == cpu && squares[2][2] == cpu)
			|| (squares[2][0] == cpu && squares[1][1] == cpu && squares[0][2] == cpu)) winner = 2;
		else winner = 0;
		
		return winner;
	}
	
	bool IsFilled()
	{
		bool filled = true;
		for (unsigned char i = 0; i < ROWS; ++i) {
			for (unsigned char j = 0; j < COLUMNS; ++j) {
				if (squares[j][i] == ' ') filled = false;
			}
		}
		return filled;
	}
};

#endif