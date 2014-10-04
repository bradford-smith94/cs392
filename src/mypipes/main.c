/*Bradford Smith (bsmith8)
*main.c mypipes project
*10/3/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mypipes.h"

/*pre: main takes command line arguments int argc and char **argv
*post: prints the string given by argv from each process (grandpa, dad
*	and child then ends and returns 0, returns -1 if any of the processes
*	fail to be created
*/
int main(int argc, char **argv)
{
	int pipe1[2];
	int pipe2[2];
	int pid;
	int n;
	char *message;

	pipe(pipe1);
	if((pid = fork()) < 0)
	{
		my_str("ERROR spwaning DAD process!");
		exit(-1);
	}
	else if(pid > 0)
	{
		/*this is GRANDPA*/
		close(pipe1[0]);
		message = my_vect2str(&argv[1]);
		//write(pipe1[1]...
		wait;
	}
	else
	{
		/*this is DAD*/
		close(pipe1[1]);
		pipe(pipe2);
		if((pid = fork()) < 0)
		{
			my_str("ERROR spawning CHILD process!");
			exit(-1);
		}
		else if(pid > 0)
		{
			/*this is still DAD*/
			close(pipe2[0]);
			//n = read(pipe1[0]...
			//write(pipe2[1]...
			wait;
		}
		else
		{
			/*this is CHILD*/
			close(pipe2[1]);
			//n = read(pipe2[0]...
		}
	}
	return 0;
}
