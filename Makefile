CFLAGS= -Wall -ansi -pedantic -O3 -fomit-frame-pointer -g
CC= gcc ${CFLAGS}
YFLAGS= -y -d
LFLAGS=
SNAME= c_compiler
LYSRC= y.tab.c lex.yy.c
LSRC= c.l
YSRC= c.y
SRC=
OBJ= $(SRC:.c=.o)
LYOBJ= $(LYSRC:.c=.o)

all : ${SNAME} clean
	@echo success making ${SNAME}
dev : ${SNAME}
	@echo success making ${SNAME}
${SNAME} : ${OBJ}
	@echo making ${SNAME}
	@flex ${LFLAGS} ${LSRC}
	@bison ${YFLAGS} ${YSRC}
	@gcc -c ${LYSRC}
	@gcc -o ${SNAME} ${LYOBJ} ${OBJ}
%.o : %.c
	@echo -n 'compiling $< ... '
	@${CC} -o $@ -c $<
	@echo done
clean :
	@echo cleaning object files
	@rm -f ${OBJ} ${LYOBJ}
cleanall : clean
	@echo cleaning executable file
	@rm -f ${SNAME}
