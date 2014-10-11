/*Bradford Smith (bsmith8)
*my_str2vect myminishell project
*10/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in a char *s
*post: returns a char** that is the vector
*	representation of s broken into substrings on whitespace
*/
char** my_str2vect(char *s)
{
	char **vect;
	int i;
	int w;/*word count*/
	int c;/*count*/
	char last;

	if(s == NULL)
		return NULL;
	w = 0;
	last = '\0';
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] != ' ' && s[i] != '\t')
			if(last == ' ' || last == '\t' || last == '\0')
				w++;
		last = s[i];
	}/*found number of words*/
	vect = (char**)xmalloc(w*sizeof(char*));
	c = 0;
	w = 0;
	last = '\0';
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] != ' ' && s[i] != '\t')
		{
			if(last == ' ' || last == '\t' || last == '\0')
				c++;
		}
		else if(c != 0)
		{
			vect[w] = (char*)xmalloc(c*sizeof(char)+1);
			w++;
			c = 0;
		}
		last = s[i];
	}/*found size of each word*/
	c = 0;
	w = 0;
	last = '\0';
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] != ' ' && s[i] != '\t')
		{
			vect[w][c] = s[i];
		}
		else if((s[i] == ' ' || s[i] == '\t') && (last != ' ' || last != '\t' || last != '\0'))
		{
			vect[w++][c] = '\0';
			c = 0;
		}
		last = s[i];
	}/*copied words to vect*/
	return vect;
}
