/*Bradford Smith (bsmith8)
*disconnect.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: called from a child process in the server
*post: disconnects the client and ends the child process
*/
void disconnect()
{
	if(close(gl_env.clientfd))
		my_err("ERROR: cannot close client socket\n");
	my_str("***");
	my_str(gl_env.clientname);
	my_str(" disconnected...\n");
	exit(0);
}
