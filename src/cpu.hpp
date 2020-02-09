#ifndef CPU_HPP
#define CPU_HPP

#include <cstdlib>

class CPU {
public:
	bool MakeMove(Board* pBoard, char character)
	{
		bool legal = true;
		unsigned char position = rand() % 9;
		
		if (position == 0 and pBoard->squares[0][0] == ' ') pBoard->squares[0][0] = character;
		else if (position == 1 and pBoard->squares[0][1] == ' ') pBoard->squares[0][1] = character;
		else if (position == 2 and pBoard->squares[0][2] == ' ') pBoard->squares[0][2] = character;
		else if (position == 3 and pBoard->squares[1][0] == ' ') pBoard->squares[1][0] = character;
		else if (position == 4 and pBoard->squares[1][1] == ' ') pBoard->squares[1][1] = character;
		else if (position == 5 and pBoard->squares[1][2] == ' ') pBoard->squares[1][2] = character;
		else if (position == 6 and pBoard->squares[2][0] == ' ') pBoard->squares[2][0] = character;
		else if (position == 7 and pBoard->squares[2][1] == ' ') pBoard->squares[2][1] = character;
		else if (position == 8 and pBoard->squares[2][2] == ' ') pBoard->squares[2][2] = character;
		else legal = false;
		
		return legal;
	}
};

#endif