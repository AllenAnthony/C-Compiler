compiler: y.tab.o lex.yy.o
	gcc -o compiler y.tab.o lex.yy.o -ly

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c:
	lex c.l

y.tab.c:
	yacc -d c.y

clean:
	rm -rf compiler *.o lex.yy.c y.tab.h y.tab.c
