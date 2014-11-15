#Bradford Smith (bsmith8)
#Makefile for gtk project 
#11/15/2014
#"I pledge my honor that I have abided by the Stevens Honor System."

SERVER=server
CLIENT=client
SERVERSRC= server.c my_err.c server_exit.c read_msg.c send_reply.c print_msg.c disconnect.c
CLIENTSRC= client.c my_err.c client_exit.c send_msg.c read_keyboard.c read_reply.c cap_sigint.c
SERVEROBJ=$(SERVERSRC:.c=.o)
CLIENTOBJ=$(CLIENTSRC:.c=.o)
RM=rm -f
INCLPATH=../../include
LIBPATH=../../lib
CFLAGS+= -I$(INCLPATH) -pedantic-errors -Wall
LDFLAGS+= -L$(LIBPATH)
LDLIBS+= -lmy
DEBUGFLGS= -g -DDEBUG
SERVERFLG= -DSERVER

all: server client

server: CFLAGS+= $(SERVERFLG)
server: $(SERVEROBJ)
	cc $(LDFLAGS) $(SERVEROBJ) $(LDLIBS) -o $(SERVER)

client: $(CLIENTOBJ)
	cc $(LDFLAGS) $(CLIENTOBJ) $(LDLIBS) -o $(CLIENT)

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
	-$(RM) $(SERVER)
	-$(RM) $(CLIENT)

re: fclean all
