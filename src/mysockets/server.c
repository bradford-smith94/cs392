/*Bradford Smith (bsmith8)
*server.c mysockets project
*10/25/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysockets.h"

/*pre: takes in an int argc and a char **argv
*post: runs the server application with argc number of command line arguments
*	given by argv
*/
int main(int argc, char **argv)
{
	int sockfd;
	int clientfd;
	int clientlen;
	struct sockaddr_in serv_addr;
	struct sockaddr_in client_addr;
	int port;

	/*check argv*/
	port = my_atoi(argv[1]);
	/*check port*/
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port(htons(port));
}
