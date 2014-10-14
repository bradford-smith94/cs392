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
	int pid;
	char *s;
	char **v;

	s = (char*)xmalloc(256*sizeof(char));
	while(1)
	{
		my_str("minishell> ");
		n = read(0, s, 256);
		#ifdef DEBUG
			my_str("n= ");
			my_int(n);
			my_char('\n');
		#endif
		s[n - 1] = '\0';
		if(n > 1)/*1 character is just a \0 (read in \n user just hit enter)*/
		{
			v = my_str2vect(s);
			if(my_strcmp(v[0], "cd") == 0)
				my_chdir(v[1]);
			else if(my_strcmp(v[0], "exit") == 0)
				break;
			else if(v[0] != NULL)/*if not just whitespace, we're going to need to fork*/
			{
				#ifdef DEBUG
					my_str("command:>");
					my_str(v[0]);
					my_str("<\n");
					my_str("going to fork\n");
				#endif
				if((pid = fork()) < 0)
					my_err("minishell: ERROR forking process!\n");
				else if(pid > 0)
					wait(NULL);
				else
				{
					my_execvp(v[0], v);
					#ifdef DEBUG
						my_str("exiting forked process\n");
					#endif
					exit(0);
					return 0;
				}
			}
			#ifdef DEBUG
				my_str("freeing vector\n");
			#endif
			my_freevect(v);
		}
		else if(n < 0)
			my_str("minishell: ERROR reading command\n");
	}
	free(s);
	my_str("Thank you for using myminishell, live long and prosper.\n");
	return 0;
}
