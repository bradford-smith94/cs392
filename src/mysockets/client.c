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
	char *name;
	char *msg;

	signal(SIGINT, client_exit);
	if(argc < 3)
		my_err("usage: ./client serverName portNumber\n");
	
	port = my_atoi(argv[2]);
	if(port < 0)
		my_err("ERROR: invalid port number\n");

	if((gl_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		my_err("ERROR: cannot create socket\n");

	if(!(server = gethostbyname(argv[1])))
		my_err("ERROR: cannot resolve hostname\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	memcpy(&serv_addr.sin_addr.s_addr, (server->h_addr), server->h_length);

	if(connect(gl_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		my_err("ERROR: cannot connect to socket\n");
	
	my_str("Enter username: ");
	name = read_keyboard();

	#ifdef DEBUG
		my_str("***DEBUG***Username: ");
		my_str(name);
		my_char('\n');
	#endif
	
	send_msg(name);
	read_reply();
	
	while(1)
	{
		my_str(name);
		my_str(": ");
		msg = read_keyboard();

		if(my_strncmp(msg, "/nick", 5) == 0)
		{
			if(my_strlen(msg) >= 7)
			{
				free(name);
				name = my_strdup(&msg[6]);
				my_str("***Changed name to ");
				my_str(name);
				my_char('\n');
			}
			else
				my_str("***usage: /nick newName\n");
		}
		else if(my_strncmp(msg, "/me", 3) == 0 && my_strlen(msg) < 5)
			my_str("***usage: /me something\n");

		send_msg(msg);
		free(msg);
		read_reply();
	}
}
