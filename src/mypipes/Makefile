#Bradford Smith (bsmith8)
#Makefile for mypipes
#10/3/2014
#"I pledge my honor that I have abided by the Stevens Honor System."

NAME=pipes
SRC= main.c my_err.c
OBJ=$(SRC:.c=.o)
RM=rm -f
INCLPATH=../../include
LIBPATH=../../lib
CFLAGS+= -I$(INCLPATH)

all: $(OBJ)
	cc -I$(INCLPATH) -L$(LIBPATH) $(OBJ) -lmy -o $(NAME)

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all
