/*Bradford Smith (bsmith8)
*my_err.c mypipes project
*10/5/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mypipes.h"

/*pre: takes in a char *s
*post: prints the error message given by s and exits with -1
*/
void my_err(char *s)
{
	my_str(s);
	exit(-1);
}
