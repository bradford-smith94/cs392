/*Bradford Smith (bsmith8)
*client.c mysockets project
*10/27/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysockets.h"

/*pre: takes in an int argc and a char **argv
*post: runs the client application with argc number of command line arguments
*	given by argv
*/
int main(int argc, char **argv)
{
	struct sockaddr_in serv_addr;
	struct hostent *server;
	int port;

	if(argc < 3)
		my_err("usage: ./client serverName portNumber\n");
	
	port = my_atoi(argv[2]);
	if(port < 0)
		my_err("ERROR: invalid port number\n");

	if((gl_sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		my_err("ERROR: cannot create socket\n");

	if(!(server = gethostbyname(argv[1])))
		my_err("ERROR: cannot resolve hostname\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = memcpy(*(server->h_addr), server->h_length);

	if(connect(gl_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		my_err("ERROR: cannot connect to socket\n");
	
	while(1)
	{
		/*read/write stuff here*/
	}
}
