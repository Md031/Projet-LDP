FLAGS=-lfltk -Wall -std=c++17
COMPILER=g++

sokoban: sokoban.cpp board.o cell.o wall.o
	${COMPILER} sokoban.cpp wall.o board.o cell.o -o sokoban ${FLAGS}

board.o: board.cpp board.hpp
	${COMPILER} -c board.cpp ${FLAGS}

cell.o : cell.cpp cell.hpp
	${COMPILER} -c cell.cpp ${FLAGS}

wall.o: wall.cpp wall.hpp
	${COMPILER} -c wall.cpp ${FLAGS}