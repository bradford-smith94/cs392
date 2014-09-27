/*Bradford Smith (bsmith8)
*xmalloc.c libmy project part 2
*9/10/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in an unsigned integer
*post: calls malloc with the given integer and provides error checking
*/
void* xmalloc(unsigned int n)
{
	void *p;
	if((p = malloc(n)) == NULL)
	{
		my_str("Virtual memory exhausted\n");
		exit(0);
	}
	return p;
}
