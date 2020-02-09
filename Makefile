build:
	g++ src/game.cpp -O2 -o bin/TicTacToe

clean:
	del bin\TicTacToe.exe

debug:
	gdb bin/TicTacToe

run:
	bin/TicTacToe