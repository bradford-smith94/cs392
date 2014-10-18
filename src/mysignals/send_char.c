/*Bradford Smith (bsmith8)
*send_char.c mysignals project
*10/18/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: takes in a char c and a pid_t serverpid
*post: sends c to serverpid with signals
*/
void send_char(char c, pid_t serverpid)
{
	int mask = 0x80;/*10000000*/
	char i;

	for(i = 0; i < 8; i++)
	{
		if(c & mask)
			kill(serverpid, SIGUSR1);
		else
			kill(serverpid, SIGUSR2);
		c <<= 1;
		pause();/*server will send ack that it got the char*/
	}
}
