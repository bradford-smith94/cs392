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
	socklen_t clientlen;
	struct sockaddr_in serv_addr;
	struct sockaddr_in client_addr;
	int port;
	int pid;
	char *msg;

	signal(SIGINT, server_exit);
	if(argc < 2)
		my_err("usage: ./server portNumber\n");

	port = my_atoi(argv[1]);
	if(port < 0)
		my_err("ERROR: invalid port number\n");

	if((gl_env.serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		my_err("ERROR: cannot create socket\n");

	serv_addr = *((struct sockaddr_in *)memset(&serv_addr, 0, sizeof(serv_addr)));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	if(bind(gl_env.serverfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)))
		my_err("ERROR: cannot bind socket\n");
	
	my_str("***Server started on port ");
	my_int(port);
	my_char('\n');

	while(1)
	{
		listen(gl_env.serverfd, 5);

		clientlen = sizeof(client_addr);
		gl_env.clientfd = accept(gl_env.serverfd, (struct sockaddr *)&client_addr, &clientlen);
		if(gl_env.clientfd < 0)
			my_err("ERROR: cannot accept connection\n");
		gl_env.clientname = read_msg();
		send_reply("/ack");

		#ifdef DEBUG
			my_str("***DEBUG***Client connected: username: ");
			my_str(gl_env.clientname);
			my_str(" going to fork!\n");
		#endif
		my_str("***");
		my_str(gl_env.clientname);
		my_str(" has connected.\n");
		if((pid = fork()) < 0)
			my_err("ERROR: cannot fork process\n");
		else if(pid == 0)
		{
			gl_env.childflg = 1;
			while(1)
			{
				msg = read_msg();
				print_msg(msg);
			}
		}
		free(gl_env.clientname);
	}
}
