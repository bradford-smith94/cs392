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

	if(pipe(pipe1))
		my_err("ERROR failed to create pipe1!");
	if((pid = fork()) < 0)
		my_err("ERROR spawning DAD process!");
	else if(pid > 0)
	{
		/*this is GRANDPA after spawning DAD*/
		if(close(pipe1[0]))
			my_err("ERROR failed to close pipe1[0] in GRANDPA process!");
		message = my_vect2str(&argv[1]);
		if(my_strlen(message) == -1){
			free(message);
			message = my_strdup("NULL");
		}
		my_str("This is Grandpa sending \"");
		my_str(message);
		my_str("\"\n");
		if((write(pipe1[1], message, 256)) < 0)
			my_err("ERROR failed to write to pipe1[1] in GRANDPA process!");
		wait();
	}
	else
	{
		/*this is DAD*/
		if(close(pipe1[1]))
			my_err("ERROR failed to close pipe1[1] in DAD process!");
		if(pipe(pipe2))
			my_err("ERROR failed to create pipe2!");
		if((pid = fork()) < 0)
			my_err("ERROR spawning CHILD process!");
		else if(pid > 0)
		{
			/*this is DAD after spawning CHILD*/
			if(close(pipe2[0]))
				my_err("ERROR failed to close pipe2[0] in DAD process!");
			n = read(pipe1[0], message, 256);
			if(n < 0)
				my_err("ERROR failed to read from pipe1[0] in DAD process!");
			my_str("This is Dad recieving and sending \"");
			my_str(message);
			my_str("\"\n");
			if((write(pipe2[1], message, 256)) < 0)
				my_err("ERROR failed to write to pipe2[1] in DAD process!");
			wait();
		}
		else
		{
			/*this is CHILD*/
			if(close(pipe2[1]))
				my_err("ERROR failed to close pipe2[1] in CHILD process!");
			n = read(pipe2[0], message, 256);
			if(n < 0)
				my_err("ERROR failed reading from pipe2[0] in CHILD process!");
			my_str("This is Child recieving \"");
			my_str(message);
			my_str("\"\n");
		}
	}
	return 0;
}
