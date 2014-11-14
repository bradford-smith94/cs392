/*Bradford Smith (bsmith8)
*send_reply.c mysockets project
*10/30/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysockets.h"

/*pre: takes in a char *s that is either "/ack", "/nack" or "/exit"
*post: sends the string s to the client
*/
void send_reply(char *s)
{
	int n;

	if((n = write(gl_env.clientfd, s, my_strlen(s))) < 0)
		my_err("ERROR: cannot reply to client\n");
}
