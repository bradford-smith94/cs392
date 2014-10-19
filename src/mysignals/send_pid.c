/*Bradford Smith (bsmith8)
*send_pid.c mysignals project
*10/18/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: takes in a pid_t mypid and a pid_t serverpid
*post: sends mypid to serverpid so the server knows who we are
*/
void send_pid(pid_t mypid, pid_t serverpid)
{
	int mask = 1 << (8*sizeof(pid_t)-1);
	char i;

	#ifdef DEBUG
		my_str("Sending pid: ");
	#endif
	
	for(i = 0; i < (8*sizeof(pid_t)); i++)
	{
		if(mypid & mask)
		{
			kill(serverpid, SIGUSR1);
			#ifdef DEBUG
				my_int(1);
			#endif
		}
		else
		{
			kill(serverpid, SIGUSR2);
			#ifdef DEBUG
				my_int(0);
			#endif
		}
		mypid <<= 1;
		usleep(3000);/*server can't ack so we sleep for a bit*/
	}
	#ifdef DEBUG
		my_char('\n');
	#endif
}
