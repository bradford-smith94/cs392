/*Bradford Smith (bsmith8)
*main.c termcaps project
*11/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: takes in an int argc and a char *argv
*post: runs the myselect program with argc number of command line arguments
*	defined by argv
*/
int main(int argc, char **argv)
{
	char enterflg;

	if(argc < 2)
	{
		my_str("usage: ./myselect files [more files]...\n");
		exit(-1);
	}
	signal(SIGWINCH, );
	init_caps();
	init_terminal();
	setup_elems();
	show_elems();
	enterflg = 0;
	while(1)
	{
		/*TODO
		read keyboard input*/
	}
	restore_terminal();
	getout(enterflg);
	return 0;
}
