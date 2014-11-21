/*Bradford Smith (bsmith8)
*cap_sigint.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: none
*post: sends the server /exit and reads the response
*/
void cap_sigint()
{
	if(gl_env.sockfd)
	{
		#ifdef DEBUG
			my_str("***DEBUG***Cap_sigint sending exit\n");
		#endif
		send_msg("/exit");
		read_reply();
	}
	else
	{
		#ifdef DEBUG
			my_str("***DEBUG***Cap_sigint calling client_exit()\n");
		#endif
		client_exit();
	}
}
