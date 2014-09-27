/*Bradford Smith (bsmith8)
*my_strpos.c libmy project
*9/8/2014 corrected on 9/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a string and a character to search for
*post: returns the index of the first occurance of the given char or -1 if not found
*/
int my_strpos(char *s, char c)
{
	unsigned int i; 
	if(s != NULL)
		for(i = 0; s[i] != '\0'; i++)
			if(s[i] == c)
				return i;
	return -1;
}
