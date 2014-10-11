/*Bradford Smith (bsmith8)
*my_freevect.c myminishell project
*10/11/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a char **vect
*post: frees each string in vect then frees vect
*/
void my_freevect(char **vect)
{
	int i;

	for(i = 0; vect[i] != NULL; i++)
		free(vect[i]);
	free(vect);
}
