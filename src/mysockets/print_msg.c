/*Bradford Smith (bsmith8)
*print_msg.c mysockets project
*10/30/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysockets.h"

/*pre: takes in a char *s
*post: parses and prints the string s
*/
void print_msg(char *msg)
{
	if(my_strncmp(msg, "/exit", 5) == 0)
	{
		send_reply("/nack");
		disconnect();
	}
	else if(my_strncmp(msg, "/nick", 5) == 0)
	{
		send_reply("/ack");
		if(my_strlen(msg) >= 7)
		{
			my_str("***");
			my_str(gl_env.clientname);
			my_str(" changed name to ");
			my_str(&msg[6]);
			my_char('\n');
			gl_env.clientname = &msg[6];
		}
	}
	else if(my_strncmp(msg, "/me", 3) == 0)
	{
		send_reply("/ack");
		if(my_strlen(msg) >= 5)
		{
			my_str("***");
			my_str(gl_env.clientname);
			my_str(&msg[3]);
			my_char('\n');
		}
	}
	else
	{
		send_reply("/ack");
		my_str(gl_env.clientname);
		my_str(": ");
		my_str(msg);
		my_char('\n');
	}
}
