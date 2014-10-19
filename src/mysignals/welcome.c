/*Bradford Smith (bsmith8)
*welcome.c mysignals project
*10/19/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysignals.h"

/*pre: none
*post: prints the server application's welcome information
*/
void welcome()
{
	my_str("Server running on pid: ");
	my_int(getpid());
	my_char('\n');
	my_str("To shut it down use: ^C\n");
	my_str("=========================\n\n");
}
