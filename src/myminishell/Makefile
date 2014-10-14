#Bradford Smith (bsmith8)
#Makefile for myminishell
#10/8/2014
#"I pledge my honor that I have abided by the Stevens Honor System."

NAME=minishell
SRC= main.c my_err.c my_chdir.c my_execvp.c
OBJ=$(SRC:.c=.o)
RM=rm -f
INCLPATH=../../include
LIBPATH=../../lib
CFLAGS+= -I$(INCLPATH) -Wall -pedantic-errors
DEBUG= -g -DDEBUG

all: $(OBJ)
	cc -I$(INCLPATH) -L$(LIBPATH) $(OBJ) -lmy -o $(NAME)

debug: fclean
debug: CFLAGS+= $(DEBUG)
debug: all

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all
