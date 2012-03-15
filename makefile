flicker:	node.o flicker.o y.flicker.o lex.flicker.o
	g++ node.o flicker.o y.flicker.o lex.flicker.o  -o flicker

lex.flicker.c: flicker.l y.flicker.h
	flex -o lex.flicker.c flicker.l

lex.flicker.o: lex.flicker.c
	gcc -c lex.flicker.c

y.flicker.c y.flicker.h:  flicker.y
	bison --yacc --defines -o y.flicker.c flicker.y

y.flicker.o: y.flicker.c y.flicker.h
	gcc -c y.flicker.c

flicker.o: flicker.cpp y.flicker.h
	g++ -c flicker.cpp

node.o: node.h node.cpp
	g++ -c node.cpp

clean: 
	rm y.* lex.* *.o flicker
