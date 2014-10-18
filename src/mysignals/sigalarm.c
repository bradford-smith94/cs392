/*Bradford Smith (bsmith8)
*sigalarm.c mysignals project
*10/18/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: none (called when an alarm rings)
*post: prints a timeout message and exits the client application
*/
void sigalarm()
{
	my_str("ERROR: timeout: no response from server\n");
	exit(-1);
}
