/*Bradford Smith (bsmith8)
*get_ack.c mysignals project
*10/18/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: none (called when we recieve acknowledgement from the server)
*post: updates the global flag gl_ack to 1
*/
void get_ack()
{
	if(gl_ack != 1)
		gl_ack = 1;
}
