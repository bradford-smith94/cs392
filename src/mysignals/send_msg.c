/*Bradford Smith (bsmith8)
*send_msg.c mysignals project
*10/18/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: takes in a char *msg and a pid_t serverpid
*post: uses the send_char() method to send msg to serverpid
*/
void send_msg(char *msg, pid_t serverpid)
{
	if(msg != NULL)
	{
		for( ; *msg != '\0'; msg++)
			send_char(*msg, serverpid);
		send_char(*msg, serverpid);/*send the \0*/
	}
}
