/*Bradford Smith (bsmith8)
*server_exit.c mysockets project
*10/28/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysockets.h"

/*pre: none
*post: prints a goodbye message and ends the server application
*/
void server_exit()
{
	my_str("***Shutting down the server...\n");
	exit(0);
}
