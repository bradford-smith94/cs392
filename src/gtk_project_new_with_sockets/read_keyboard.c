/*Bradford Smith (bsmith8)
*read_keyboard.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: none
*post: returns a pointer to an allocated string read in from the keyboard
*/
char* read_keyboard()
{
	char buf[256];
	int n;

	if((n = read(0, buf, 255)) < 0)
		my_err("ERROR: cannot read from keyboard\n");
	buf[n - 1] = '\0';

	return my_strdup(buf);
}
