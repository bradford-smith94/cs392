/*Bradford Smith (bsmith8)
*my_chdir.c myminishell project
*10/12/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myminishell.h"
#include "errno.h"/*included for access to errno and the error constants*/

/*pre: takes in a char *path
*post: changes the current working directory to the one specified by path
*	handles and prints errors and remains in the current working directory
*	if an error occured
*/
void my_chdir(char *path)
{
	int n;
	
	if(path != NULL && (my_strcmp(path, ".") != 0))
	{
		n = chdir(path);
		if(n < 0)
		{
			my_str("minishell: cd: ");
			my_str(path);
			if(errno == EACCES)
				my_str(": permission denied\n");
			else if(errno == EFAULT)
				my_str(": path is outside of the allocated address space\n");
			else if(errno == EIO)
				my_str(": I/O error\n");
			else if(errno == ELOOP)
				my_str(": too many redirects\n");
			else if(errno == ENAMETOOLONG)
				my_str(": path too long\n");
			else if(errno == ENOENT)
				my_str(": path does not exist\n");
			else if(errno == ENOMEM)
				my_str(": insufficient kernel memory\n");
			else if(errno == ENOTDIR)
				my_str(": is not a directory\n");
			else
				my_str(": unspecified error\n");
		}
	}
}
