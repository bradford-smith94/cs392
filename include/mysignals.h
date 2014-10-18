/*Bradford Smith (bsmith8)
*mysignals.h mysignals project header file
*10/17/2014
*"I pedge my honor that I have abided by the Stevens Honor System."
*/

#ifndef _MYSIGNALS_H_
#define _MYSIGNALS_H_

#include "my.h"

#ifdef SERVER
	struct s_env
	{
		pid_t clientpid;
		char done;
	}		gl_env;
#else
	char gl_ack;
#endif

/* This is the header for the mysignals project,
* it runs a client and server application where the client can send messages
* to the server via signals.
*/
#ifdef SERVER
	int main();
	void get_char(int);
	void get_clientpid(int);
	void goodbye();
#else
	int main(int, char**);
	void send_msg(char*, pid_t);
	void send_char(char, pid_t);
	void send_pid(pid_t, pid_t);
	void get_ack();
	void sigalarm();
#endif

#endif
