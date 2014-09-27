#Bradford Smith (bsmith8)
#Makefile for libmylist project
#9/20/2014
#"I pledge my honor that I have abided by the Stevens Honor System."

NAME=libmylist.a
SRC= new_node.c add_node.c traverse_string.c traverse_int.c traverse_char.c \
	add_elem.c append.c add_node_at.c remove_node.c remove_node_at.c remove_last.c \
	count_nodes.c empty_list.c node_at.c elem_at.c
OBJ=$(SRC:.c=.o)
RM=rm -f
INCLPATH=../../include
LIBPATH=../../lib
CFLAGS+= -I$(INCLPATH)
LDFLAS+= -L$(LIBPATH)
LDLIBS+= -lmy

all: $(OBJ)
	ar -rc $(LIBPATH)/$(NAME) $(OBJ)
	ranlib $(LIBPATH)/$(NAME)

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all
