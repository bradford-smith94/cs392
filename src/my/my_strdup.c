/*Bradford Smith (bsmith8)
*my_strdup.c libmy project part 2
*9/12/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a string
*post: returns a pointer to an allocated copy of the given string
*/
char* my_strdup(char* s)
{
	unsigned int i;
	char *r;
	if(s == NULL)
		r = NULL;
	else{
		r = (char*)xmalloc(my_strlen(s) + 1);
		for(i = 0; i < my_strlen(s); i++)
			r[i] = s[i];
		r[i] = '\0';
	}
	return r;
}
