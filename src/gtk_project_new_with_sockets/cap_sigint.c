/*Bradford Smith (bsmith8)
*cap_sigint.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: none
*post: sends the server /exit and reads the response
*/
void cap_sigint()
{
	send_msg("/exit");
	read_reply();
}
