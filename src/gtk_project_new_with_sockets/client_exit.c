/*Bradford Smith (bsmith8)
*client_exit.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: none
*post: prints a goodbye message and exits the client application
*/
void client_exit()
{
	my_str("\n***Exiting the client program...\n");
	exit(0);
}
