/*Bradford Smith (bsmith8)
*my_strlen.c libmy project
*9/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a string
*post: returns the length of the given string
*/
int my_strlen(char* s)
{
	unsigned int n = -1;
	if(s != NULL){
		n++;
		for(s; *s != '\0'; s++)
			n++;
	}
	return n;
}
