FLAGS=-lfltk -Wall -std=c++17
COMPILER=g++

sokoban: main.cpp board.o cell.o wall.o player.o box.o move.o target.o teleportation.o view.o controller.o
	${COMPILER} main.cpp wall.o board.o cell.o player.o box.o move.o target.o teleportation.o view.o controller.o -o sokoban ${FLAGS}

board.o: ./Model/board.cpp ./Model/board.hpp
	${COMPILER} -c ./Model/board.cpp ${FLAGS}

cell.o : ./Model/cell.cpp ./Model/cell.hpp
	${COMPILER} -c ./Model/cell.cpp ${FLAGS}

wall.o: ./Model/wall.cpp ./Model/wall.hpp
	${COMPILER} -c ./Model/wall.cpp ${FLAGS}

player.o: ./Model/player.cpp ./Model/player.hpp
	${COMPILER} -c ./Model/player.cpp ${FLAGS}

box.o: ./Model/box.cpp ./Model/box.hpp
	${COMPILER} -c ./Model/box.cpp ${FLAGS}

move.o: ./Model/move.cpp ./Model/move.hpp
	${COMPILER} -c ./Model/move.cpp ${FLAGS}

target.o: ./Model/target.cpp ./Model/target.hpp
	${COMPILER} -c ./Model/target.cpp ${FLAGS}

teleportation.o: ./Model/teleportation.cpp ./Model/teleportation.hpp
	${COMPILER} -c ./Model/teleportation.cpp ${FLAGS}

controller.o:./Controller/controller.cpp ./Controller/controller.hpp 
	${COMPILER} -c ./Controller/controller.cpp ${FLAGS}

view.o:./View/view.cpp ./View/view.hpp 
	${COMPILER} -c ./View/view.cpp ${FLAGS} 

clean:
	-rm *.o 2> /dev/null