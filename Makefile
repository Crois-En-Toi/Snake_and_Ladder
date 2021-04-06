.PHONY: clean

Test_game: test.o board.o 
	gcc test.o board.o -g -o Test_game
Game: game.o board.o snake_and_ladder.o
	gcc game.o board.o snake_and_ladder.o -g -o Game

snake_and_ladder.o: snake_and_ladder.c board.h snake_and_ladder.h
	gcc -g -c snake_and_ladder.c

test.o: test.c board.h
	gcc -g -c test.c

board.o: board.c board.h
	gcc -g -c board.c

clean:
	rm test.o board.o Test_game
