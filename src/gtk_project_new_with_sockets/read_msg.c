/*Bradford Smith (bsmith8)
*read_msg.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: none
*post: returns a pointer to an allocated string read in from the client
*/
char* read_msg()
{
	char buf[256];
	int n;

	if((n = read(gl_env.clientfd, buf, 255)) < 0)
		my_err("ERROR: cannot read from client\n");
	buf[n] = '\0';/*make sure the last character is \0*/

	return my_strdup(buf);
}
