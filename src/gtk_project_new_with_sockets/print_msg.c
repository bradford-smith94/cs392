/*Bradford Smith (bsmith8)
*print_msg.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a char *s
*post: parses and prints the string s
*/
void print_msg(char *msg)
{
	if(my_strncmp(msg, "/exit", 5) == 0)
	{
		if(my_strlen(msg) > 5)
		{
			if(msg[5] != ' ' && msg[5] != '\t')
			{
				send_reply("/ack");
				my_str(gl_env.clientname);
				my_str(": ");
				my_str(msg);
				my_char('\n');
			}
		}
		send_reply("/nack");
		disconnect();	
	}
	else if(my_strncmp(msg, "/nick", 5) == 0)
	{
		send_reply("/ack");
		msg += 5;
		for(; *msg != '\0'; msg++)
				if(*msg != ' ' && *msg != '\t')
					break;

		if(my_strlen(msg))
		{
			my_str("***");
			my_str(gl_env.clientname);
			my_str(" changed name to ");
			my_str(msg);
			my_char('\n');
			gl_env.clientname = msg;
		}
	}
	else if(my_strncmp(msg, "/me", 3) == 0)
	{
		send_reply("/ack");
		msg += 3;
		for(; *msg != '\0'; msg++)
				if(*msg != ' ' && *msg != '\t')
					break;

		if(my_strlen(msg))
		{
			my_str("***");
			my_str(gl_env.clientname);
			my_char(' ');
			my_str(msg);
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
