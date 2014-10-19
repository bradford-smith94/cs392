/*Bradford Smith (bsmith8)
*get_clientpid.c mysignals project
*10/18/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: takes in an int sig (called when the client is sending its pid)
*post: after recieving all the bits in the pid saves it in the global struct
*/
void get_clientpid(int sig)
{
	static char count = 0;
	static pid_t p = 0;

	p <<= 1;
	if(sig == SIGUSR1)
	{
		p |= 1;
	#ifdef DEBUG
		my_int(1);
	}
	else
	{
		my_int(0);
	#endif
	}
	count++;
	if(count == (8*sizeof(pid_t)))
	{
		gl_env.clientpid = p;
		p = 0;
		count = 0;
		#ifdef DEBUG
			my_char('\n');
		#endif
	}
}
