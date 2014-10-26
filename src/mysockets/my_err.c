/*Bradford Smith (bsmith8)
*my_err.c mysockets project
*10/26/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysockets.h"

/*pre: takes in a char *s
*post: prints s and exits with -1
*/
void my_err(char *s)
{
	my_str(s);
	exit(-1);
}
