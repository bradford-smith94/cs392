/*Bradford Smith (bsmith8)
*my_vect2str.c mypipes project
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in char **vect
*post: returns an allocated string of all the strings in the vector seperated by spaces
*/
char* my_vect2str(char **vect)
{
	char *result;
	unsigned int len;
	int i;
	int j;
	int k;

	if(vect == NULL || *vect == NULL)
		return NULL;
	else
	{
		len = 0;
		for(i = 0; vect[i] != NULL; i++)
		{
			for(j = 0; vect[i][j] != '\0'; j++)
				len++;
			len++;
		}
		result = (char*)xmalloc(len*sizeof(char));
		k = 0;
		for(i = 0; vect[i] != NULL; i++)
		{
			for(j = 0; vect[i][j] != '\0'; j++)
				result[k++] = vect[i][j];
			result[k++] = ' ';
		}
		result[--k] = '\0';
	}
	return result;
}
