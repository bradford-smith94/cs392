/*Bradford Smith (bsmith8)
*my_execvp.c myminishell project
*10/13/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myminishell.h"
#include "errno.h"/*included for access to the errno variable and error constants*/

/*pre: takes in a char *prog and char **argv
*post: executes the program defined by prog with arguments defined by argv
*	also checks for and handles printing error messages
*/
void my_execvp(char *prog, char **argv)
{
	if((execvp(prog, argv)) == -1)
	{
		my_str("minishell: ");
		my_str(prog);
		if(errno == E2BIG)
			my_str(": too many arguments\n");
		else if(errno == EACCES)
			my_str(": permission denied\n");
		else if(errno == EFAULT)
			my_str(": command is outside the accessible address space\n");
		else if(errno == EINVAL)
			my_str(": ELF executable tried to name more than one interpreter\n");
		else if(errno == EIO)
			my_str(": I/O error\n");
		else if(errno == EISDIR)
			my_str(": ELF interpreter is a directory\n");
		else if(errno == ELIBBAD)
			my_str(": ELF interpreter is not in a recognized format\n");
		else if(errno == ELOOP)
			my_str(": too many redirects\n");
		else if(errno == EMFILE)
			my_str(": process has too many files open\n");
		else if(errno == ENAMETOOLONG)
			my_str(": command is too long\n");
		else if(errno == ENFILE)
			my_str(": too many files open\n");
		else if(errno == ENOENT)
			my_str(": command not found\n");
		else if(errno == ENOEXEC)
			my_str(": cannot execute\n");
		else if(errno == ENOMEM)
			my_str(": insufficient kernel memory\n");
		else if(errno == ENOTDIR)
			my_str(": not a valid directory\n");
		else if(errno == EPERM)
			my_str(": permission denied\n");
		else if(errno == ETXTBSY)
			my_str(": already open for writing in another process\n");
		else
			my_str(": unspecified error\n");
	}
}
