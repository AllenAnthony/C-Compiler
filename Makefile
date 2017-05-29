compiler: y.tab.o lex.yy.o util.o abs.o
	gcc -o compiler y.tab.o lex.yy.o util.o abs.o -ly

y.tab.o: y.tab.c util.h
	gcc -c y.tab.c

lex.yy.o: lex.yy.c util.h
	gcc -c lex.yy.c

util.o: util.c util.h abs.h
	gcc -c util.c

lex.yy.c: c.l util.h abs.h
	lex c.l

y.tab.c: c.y util.h abs.h
	yacc -d c.y -v

abs.o: abs.h abs.c
	gcc -c abs.c

clean:
	rm -rf compiler lex.yy.c *.tab.h *.tab.c *.o *.output cmake-build-debug
