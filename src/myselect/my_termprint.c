/*Bradford Smith (bsmith8)
*my_termprint.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: takes in an int n
*post: returns the number of bytes written to the terminal by printing n
*/
int my_termprint(int n)
{
	return write(1, &n, 1);
}
