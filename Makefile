compiler: y.tab.o lex.yy.o util.o
	gcc -o compiler y.tab.o lex.yy.o util.o -ly

y.tab.o: y.tab.c util.h
	gcc -c y.tab.c

lex.yy.o: lex.yy.c util.h
	gcc -c lex.yy.c

util.o: util.c util.h
	gcc -c util.c

lex.yy.c: c.l util.h
	lex c.l

y.tab.c: c.y util.h
	yacc -d c.y -v

clean:
	rm -rf compiler lex.yy.c y.tab.h y.tab.c *.o y.output
