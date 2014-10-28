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
	int pid;

	if(argc < 2)
		my_err("usage: ./server portNumber\n");

	port = my_atoi(argv[1]);
	if(port < 0)
		my_err("ERROR: invalid port number\n");

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		my_err("ERROR: cannot create socket\n");

	serv_addr = memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port(htons(port));
	serv_addr.sin_addr.s_addr = INADDR_ANY

	if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)))
		my_err("ERROR: cannot bind socket\n");
	
	while(1)
	{
		listen(sockfd, 5);

		clientlen = sizeof(client_addr);
		if((clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen)) < 0)
			my_err("ERROR: cannot accept connection\m");
		if((pid = fork()) < 0)
			my_err("ERROR: cannot fork process\n");
		else if(pid == 0)
		{
			while(1)
			{
				/*read and write to client here*/
			}
		}
	}
}
