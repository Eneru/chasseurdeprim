CC = gcc
CFLAGS = -Wall -g
IFLAGS = -Iinclude

OPATH = obj/
BPATH = bin/

vpath %.c src/
vpath %.h include/
vpath %.o obj/
vpath main bin/

main : main.o | bin
	$(CC) $(CFLAGS) $(LFLAGS) -o $(BPATH)main $(OPATH)main.o

main.o : main.c base.h 

%.o : %.c | obj
	$(CC) $(CFLAGS) -o $(OPATH)$@ -c $< $(IFLAGS)

obj :
	mkdir obj

lib :
	mkdir lib

bin :
	mkdir bin

clean :
	rm obj/* bin/*

cleanall : clean
	rm -r doc/*

archive :
	tar -f meyer_razanajato-ProjetSDA2P.tar.gz -cvz src/*.c include/*.h makefile Doxyfile
