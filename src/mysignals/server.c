/*Bradford Smith (bsmith8)
*server.c mysignals project
*10/17/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: none
*post: sets up the server and waits for a client to connect,
*	then prints the message(s) that the client sends
*/
int main()
{
	int i;

	my_str("Server running on pid: ");
	my_int(getpid());
	my_char('\n');
	signal(SIGINT, goodbye);
	while(1)
	{
		signal(SIGUSR1, get_clientpid);
		signal(SIGUSR2, get_clientpid);
		for(i = 0; i < (8*sizeof(int)); i++)
			pause();
		signal(SIGUSR1, get_char);
		signal(SIGUSR2, get_char);
		kill(gl_env.clientpid, SIGUSR1);
		while(!gl_env.done)
			pause();
		my_str("=========================\n\n");
	}
	return 0;
}
