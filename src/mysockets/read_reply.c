/*Bradford Smith (bsmith8)
*read_reply.c mysockets project
*10/30/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysockets.h"

/*pre: none 
*post: reads the server reply, exits for an "/exit" or "/nack"
*	returns normally for an "/ack"
*/
void read_reply()
{
	char r[256];
	int n;

	if((n = read(gl_sockfd, r, 255)) < 0)
		my_err("ERROR: cannot read reply from server\n");
	r[n] = '\0';/*make sure the last character is \0*/
	if(my_strcmp(r, "/exit") == 0)
	{
		/*server is forcing a disconnect*/
		my_str("***Server shutting down...\n");
		client_exit();
	}
	else if(my_strcmp(r, "/nack") == 0)
	{
		/*server acknowledged exit request*/
		client_exit();
	}
	else if(my_strcmp(r, "/ack") != 0)
		my_err("ERROR: invalid server reply\n");
}
