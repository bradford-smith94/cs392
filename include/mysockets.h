/*Bradford Smith (bsmith8)
*mysockets.h mysockets project header file
*10/25/2014
*"I pedge my honor that I have abided by the Stevens Honor System."
*/

#ifndef _MYSIGNALS_H_
#define _MYSIGNALS_H_

#include "my.h"
#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>/*for memset and memcpy*/

#ifdef SERVER
	struct s_env
	{
		int serverfd;
		int clientfd;
		char *clientname;
		char childflg;
	}		gl_env;
#else
	#include <netdb.h>
	int gl_sockfd;	
#endif

/* This is the header for the mysockets project,
* it runs a client and server application where the client can send messages
* to the server using sockets. This application can support multiple client
* connections.
*/
int main(int, char**);
void my_err(char*);
#ifdef SERVER
	void server_exit();
	void send_reply(char*);
	char* read_msg();
	void print_msg(char*);
	void disconnect();
#else
	void client_exit();
	void send_msg(char*);
	char* read_keyboard();
	void read_reply();
	void cap_sigint();
#endif

#endif
