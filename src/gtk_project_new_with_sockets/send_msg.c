/*Bradford Smith (bsmith8)
*send_msg.c mysockets project
*10/30/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mysockets.h"

/*pre: takes in a char *s
*post: sends the string s to the server at gl_sockfd
*/
void send_msg(char *s)
{
	int n;

	if((n = write(gl_sockfd, s, my_strlen(s))) < 0)
		my_err("ERROR: cannot write to server\n");
}
