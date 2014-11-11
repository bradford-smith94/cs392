#Bradford Smith (bsmith8)
#Makefile for myselect
#11/7/2014
#"I pledge my honor that I have abided by the Stevens Honor System."

NAME=myselect
SRC=main.c refreshin.c refreshout.c moveup.c movedown.c moveleft.c moveright.c \
	doselect.c term_get_cap.c my_termprint.c term_clear.c term_move_to_item.c \
	show_elems.c init_caps.c get_win_size.c term_vi.c term_ve.c \
	term_underline.c term_underend.c term_standout.c term_standend.c \
	init_terminal.c restore_terminal.c setup_elems.c getout.c
OBJ=$(SRC:.c=.o)
RM=rm -f
INCLPATH=../../include
LIBPATH=../../lib
CFLAGS+= -I$(INCLPATH) -pedantic-errors -Wall
LDFLAGS+= -L$(LIBPATH)
LDLIBS+= -lmy -ltermcap
DEBUGFLGS= -g -DDEBUG

all: $(OBJ)
	cc $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

debug: fclean
debug: CFLAGS+= $(DEBUGFLGS)
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
