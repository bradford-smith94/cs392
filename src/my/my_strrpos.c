/*Bradford Smith (bsmith8)
*my_strrpos.c libmy project
*9/8/2014 corrected on 9/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a string and a character to search for
*post: returns the index of the last occurance of the given char
*/
int my_strrpos(char *s, char c)
{
	int returnIndex = -1;
	unsigned int i = 0;
	
	if(s != NULL){
		for(i; s[i] != '\0'; i++)
			if(s[i] == c)
				returnIndex = i;
	}
	return returnIndex;
}
