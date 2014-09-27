/*Bradford Smith (bsmith8)
*my_revstr.c libmy project
*9/8/2014 corrected on 9/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a string
*post: reverses the string and returns it's length
*/
int my_revstr(char* s)
{
	int len = my_strlen(s);
	int first;
	
	for(first = 0; first < len/ 2; first++)
	{
		s[first] ^= s[len - first - 1];
		s[len - first - 1] ^= s[first];
		s[first] ^= s[len - first - 1];
	}
	return len;
}
