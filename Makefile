CC=cc
OBJS=game.o moves.o printFunc.o  main.o
EXEC=2048
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@


game.o: game.c game.h moves.h printFunc.h
main.o: main.c game.h
moves.o: moves.c game.h moves.h
printFunc.o: printFunc.c printFunc.h



clean: 
	rm -f $(EXEC) $(OBJS)
	
