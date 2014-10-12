/*Bradford Smith (bsmith8)
*main.c myminishell project
*10/11/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myminishell.h"

/*pre: takes in int argc and char **argv
*post: runs the minishell program 
*	with argc number of command line arguments defined by argv
*/
int main(int argc, char **argv)
{
	int n;
	char *s;
	char **v;

	s = (char*)xmalloc(256*sizeof(char));
	while(1)
	{
		my_str("minishell prompt> ");
		n = read(0, s, 256);
		s[n - 1] = '\0';
		if(n > 1)/*1 character is just a \0 (read in \n user just hit enter)*/
		{
			v = my_str2vect(s);
			if(my_strcmp(v[0], "cd") == 0)
			{
				if(v[1] != NULL)
					my_chdir(v[1]);
				else
					my_chdir("~");
			}
			else if(my_strcmp(v[0], "exit") == 0)
				break;
			else
			{
				/*need to fork here*/
				my_str(v[0]);
				my_str("<\\n\n");
			}
		}
		else if(n < 0)
			my_err("minishell: ERROR reading command\n");
	}
	my_str("Thank you for using myminishell, live long and prosper.\n");
	return 0;
}
