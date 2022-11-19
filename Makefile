FLAGS=-lfltk  -Wall -std=c++17
COMPILER=g++

sokoban: sokoban.cpp cells.o board.o
	${COMPILER} sokoban.cpp cells.o board.o -o sokoban ${FLAGS}

cells.o: cells.cpp cells.hpp
	${COMPILER} -c cells.cpp ${FLAGS}

board.o: board.cpp board.hpp
	${COMPILER} -c board.cpp ${FLAGS}