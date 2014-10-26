#Bradford Smith (bsmith8)
#Makefile for mysockets
#10/25/2014
#"I pledge my honor that I have abided by the Stevens Honor System."

SERVER=server
CLIENT=client
SERVERSRC= server.c my_err.c
CLIENTSRC= client.c my_err.c
SERVEROBJ=$(SERVERSRC:.c=.o)
CLIENTOBJ=$(CLIENTSRC:.c=.o)
RM=rm -f
INCLPATH=../../include
LIBPATH=../../lib
CFLAGS+= -I$(INCLPATH) -pedantic-errors -Wall
LDFLAGS+= -I$(INCLPATH) -L$(LIBPATH)
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
