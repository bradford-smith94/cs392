/*Bradford Smith (bsmith8)
*my_err.c myminishell project
*10/12/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myminishell.h"

/*pre: takes in a char *s
*post: prints the error message given by s and exits with -1
*/
void my_err(char *s)
{
	my_str(s);
	exit(-1);
}
