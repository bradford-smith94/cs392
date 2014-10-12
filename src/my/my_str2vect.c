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
	int len;
	char last;

	if(s == NULL)
		return NULL;
	w = 0;
	len = 1;
	last = '\0';
	/*my_str("start loop 1\n");*/
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] != ' ' && s[i] != '\t')
			if(last == ' ' || last == '\t' || last == '\0')
				w++;
		last = s[i];
		len++;
	}/*found number of words and length*/
	/*my_str("length: ");
	my_int(len);
	my_char('\n');
	my_str("words: ");
	my_int(w);
	my_char('\n');*/
	if(w > 0)
		vect = (char**)xmalloc(w*sizeof(char*));
	else
	{
		vect = (char**)xmalloc(sizeof(char*));
		*vect = NULL;
		return vect;
	}	
	c = 0;
	w = 0;
	last = '\0';
	/*my_str("start loop 2\n");*/
	for(i = 0; i <= len; i++)
	{
		if(s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
			c++;
		else if(c != 0)
		{
			/*my_str("Word size: ");
			my_int(c);
			my_char('\n');*/
			vect[w++] = (char*)xmalloc(c*sizeof(char)+1);
			c = 0;
		}
		last = s[i];
	}/*found size of each word*/
	c = 0;
	w = 0;
	last = '\0';
	/*my_str("start loop 3\n");*/
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] != ' ' && s[i] != '\t')
		{
			/*my_str("adding a letter\n");*/
			vect[w][c++] = s[i];
		}
		else if(last != ' ' && last != '\t' && last != '\0')
		{
			/*my_str("adding a \\0\n");*/
			vect[w++][c] = '\0';
			c = 0;
		}
		last = s[i];
	}/*copied words to vect*/
	/*my_str("returning\n");*/
	return vect;
}
