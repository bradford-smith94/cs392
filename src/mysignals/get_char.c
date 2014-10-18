/*Bradford Smith (bsmith8)
*get_char.c mysignals project
*10/18/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: takes in an int sig (called when the client is sending char)
*post: after recieving 8 bits prints a character
*/
void get_char(int sig)
{
	static char count = 0;
	static char c = 0;

	c <<= 1;
	if(sig == SIGUSR1)
		c |= 1;
	count++;
	if(count == 8)
	{
		if(c == '\0')
			gl_env.done = 1;
		else
			my_char(c);
		c = 0;
		count = 0;
	}
	kill(gl_env.clientpid, SIGUSR1);/*send ack that we got the char*/
}
