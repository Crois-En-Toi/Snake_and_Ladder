.PHONY: clean

Test_game: test.o board.o
	gcc test.o board.o -g -o Test_game

test.o: test.c board.h
	gcc -g -c test.c

board.o: board.c board.h
	gcc -g -c board.c

clean:
	rm test.o board.o Test_game
