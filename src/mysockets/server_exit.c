/*Bradford Smith (bsmith8)
*server_exit.c mysockets project
*10/28/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysockets.h"

/*pre: none
*post: prints a goodbye message and ends the server application
*/
void server_exit()
{
	if(gl_env.childflg)
	{
		usleep(getpid()*100);
		send_reply("/exit");
		disconnect();
		#ifdef DEBUG
			my_str("***DEBUG***Exiting child process\n");
		#endif
	}
	else
	{
		my_char('\n');
		usleep(getpid()*200);
		if(close(gl_env.serverfd))
			my_err("ERROR: cannot safely close the socket\n");
		my_str("\n***Shutting down the server...\n");
	}
	exit(0);
}
