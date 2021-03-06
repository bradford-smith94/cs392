/*Bradford Smith (bsmith8)
*read_reply.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: none 
*post: reads the server reply, exits for an "/exit" or "/nack"
*	returns normally for an "/ack"
*/
void read_reply()
{
	char r[256];
	int n;
	
	#ifdef DEBUG
		my_str("***DEBUG***Reading server reply\n");
	#endif
	if((n = read(gl_env.sockfd, r, 255)) < 0)
		my_err("ERROR: cannot read reply from server\n");
	r[n] = '\0';/*make sure the last character is \0*/
	if(my_strcmp(r, "/exit") == 0)
	{
		/*server is forcing a disconnect*/
		my_str("***Server shut down...\n");
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
