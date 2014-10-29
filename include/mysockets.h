/*Bradford Smith (bsmith8)
*mysockets.h mysockets project header file
*10/25/2014
*"I pedge my honor that I have abided by the Stevens Honor System."
*/

#ifndef _MYSIGNALS_H_
#define _MYSIGNALS_H_

#include "my.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>/*for memset*/

#ifdef SERVER
#else
	#include <netdb.h>
	int gl_sockfd = 0;	
#endif

/* This is the header for the mysockets project,
* it runs a client and server application where the client can send messages
* to the server using sockets. This application can support multiple client
* connections.
*/
int main(int, char**);
void my_err(char*);
#ifdef SERVER
#else
#endif

#endif
