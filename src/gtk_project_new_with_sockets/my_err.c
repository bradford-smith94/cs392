/*Bradford Smith (bsmith8)
*my_err.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in a char *s
*post: prints s and exits with -1
*/
void my_err(char *s)
{
	my_str(s);
	exit(-1);
}
