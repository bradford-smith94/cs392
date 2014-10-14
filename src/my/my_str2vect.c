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
	#ifdef DEBUG
		my_str("[my_str2vect.c]\n");
		my_str("start loop 1\n");
	#endif
	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] != ' ' && s[i] != '\t')
			if(last == ' ' || last == '\t' || last == '\0')
				w++;
		last = s[i];
		len++;
	}/*found number of words and length*/
	#ifdef DEBUG
		my_str("length: ");
		my_int(len);
		my_char('\n');
		my_str("words: ");
		my_int(w);
		my_char('\n');
	#endif
	if(w > 0)
		vect = (char**)xmalloc(w*sizeof(char*)+1);
	else
	{
		vect = (char**)xmalloc(sizeof(char*));
		*vect = NULL;
		return vect;
	}	
	c = 0;
	w = 0;
	last = '\0';
	#ifdef DEBUG
		my_str("start loop 2\n");
	#endif
	for(i = 0; i <= len; i++)
	{
		if(s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
			c++;
		else if(c != 0)
		{
			#ifdef DEBUG
				my_str("Word size: ");
				my_int(c);
				my_char('\n');
			#endif
			vect[w++] = (char*)xmalloc(c*sizeof(char)+1);
			c = 0;
		}
		last = s[i];
	}/*found size of each word*/
	vect[w] = (char*)xmalloc(sizeof(char));/*allocate for last NULL*/
	c = 0;
	w = 0;
	last = '\0';
	#ifdef DEBUG
		my_str("start loop 3\n");
	#endif
	for(i = 0; i <= len; i++)
	{
		if(s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{	
			#ifdef DEBUG
				my_str("adding a letter\n");
			#endif
			vect[w][c++] = s[i];
		}
		else if(last != ' ' && last != '\t' && last != '\0')
		{
			#ifdef DEBUG
				my_str("adding a \\0\n");
			#endif
			vect[w++][c] = '\0';
			c = 0;
		}
		last = s[i];
	}/*copied words to vect*/
	vect[w] = NULL;/*added last NULL*/
	#ifdef DEBUG
		my_str("[my_str2vect.c] returning\n");
	#endif
	return vect;
}
