/*Bradford Smith (bsmith8)
*client.c mysignals project
*10/17/2014
*"I pledge my honor that I have abided the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: take in an int argc (number of args) 
*	and a char **argv (serverpid, followed by message)
*post: runs the client application in which it connects to the server
*	at the given pid and sends it the given message
*/
int main(int argc, char **argv)
{
	pid_t serverpid;

	if(argc >= 3)
	{
		serverpid = my_atoi(argv[1]);
		if(serverpid == 0)
		{
			my_str("error parsing serverpid\n");
			return -1;
		}
		signal(SIGUSR1, get_ack);
		signal(SIGALRM, sigalarm);
		send_pid(getpid(), serverpid);
		if(!gl_ack)
		{
			alarm(2);
			pause();
		}
		alarm(0);
		send_msg(my_vect2str(&argv[2]), serverpid);
	}
	else
	{
		my_str("usage: ./client serverpid message\n");
		exit(-1);
	}
	return 0;
}
