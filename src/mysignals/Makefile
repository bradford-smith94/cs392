#Bradford Smith (bsmith8)
#Makefile for mysignals
#10/17/2014
#"I pledge my honor that I have abided by the Stevens Honor System."

SERVER=server
CLIENT=client
SERVERSRC= server.c get_char.c get_clientpid.c goodbye.c
CLIENTSRC= client.c send_msg.c send_char.c send_pid.c get_ack.c sigalarm.c
SERVEROBJ=$(SERVERSRC:.c=.o)
CLIENTOBJ=$(CLIENTSRC:.c=.o)
RM=rm -f
INCLPATH=../../include
LIBPATH=../../lib
CFLAGS+= -I$(INCLPATH) -pedantic-errors -Wall
DEBUGFLGS= -g -DDEBUG
SERVERFLG= -DSERVER

all: server client

server: CFLAGS+= $(SERVERFLG)
server: $(SERVEROBJ)
	cc -I$(INCLPATH) -L$(LIBPATH) $(SERVEROBJ) -lmy -o $(SERVER)

client: $(CLIENTOBJ)
	cc -I$(INCLPATH) -L$(LIBPATH) $(CLIENTOBJ) -lmy -o $(CLIENT)

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
