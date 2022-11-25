FLAGS=-lfltk -Wall -std=c++17
COMPILER=g++
EXECPATH = \executable\

sokoban: sokoban.cpp board.o cell.o wall.o player.o box.o move.o
	${COMPILER} sokoban.cpp wall.o board.o cell.o player.o box.o move.o -o sokoban ${FLAGS}

board.o: board.cpp board.hpp
	${COMPILER} -c board.cpp ${FLAGS}

cell.o : cell.cpp cell.hpp
	${COMPILER} -c cell.cpp ${FLAGS}

wall.o: wall.cpp wall.hpp
	${COMPILER} -c wall.cpp ${FLAGS}

player.o: player.cpp player.hpp
	${COMPILER} -c player.cpp ${FLAGS}

box.o: box.cpp box.hpp
	${COMPILER} -c box.cpp ${FLAGS}

move.o: move.cpp move.hpp
	${COMPILER} -c move.cpp ${FLAGS}