#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
public:
	bool MakeMove(Board* pBoard, unsigned char position, char character)
	{
		bool legal = true;
		
		if (position == 1 and pBoard->squares[0][0] == ' ') pBoard->squares[0][0] = character;
		else if (position == 2 and pBoard->squares[0][1] == ' ') pBoard->squares[0][1] = character;
		else if (position == 3 and pBoard->squares[0][2] == ' ') pBoard->squares[0][2] = character;
		else if (position == 4 and pBoard->squares[1][0] == ' ') pBoard->squares[1][0] = character;
		else if (position == 5 and pBoard->squares[1][1] == ' ') pBoard->squares[1][1] = character;
		else if (position == 6 and pBoard->squares[1][2] == ' ') pBoard->squares[1][2] = character;
		else if (position == 7 and pBoard->squares[2][0] == ' ') pBoard->squares[2][0] = character;
		else if (position == 8 and pBoard->squares[2][1] == ' ') pBoard->squares[2][1] = character;
		else if (position == 9 and pBoard->squares[2][2] == ' ') pBoard->squares[2][2] = character;
		else {
			legal = false;
			std::cout << "This square already has a value" << std::endl;
		}
		
		return legal;
	}
};

#endif