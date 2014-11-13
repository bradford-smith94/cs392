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
	char buf[256];
	int n;

	if(argc < 2)
	{
		my_str("usage: ./myselect files [more files]...\n");
		exit(-1);
	}
	signal(SIGWINCH, show_elems);
	init_terminal();/*calls init_caps, term_vi, and term_clear*/
	setup_elems(argc - 1, &argv[1]);
	show_elems();
	while(1)
	{
		if((n = read(0, buf, 255)) < 0)
		{
			my_str("ERROR: cannot read from keyboard\n");
			getout(0);
		}
		buf[n] = '\0';
		if(my_strcmp(buf, KU) == 0)
			moveup();
		else if(my_strcmp(buf, KD) == 0)
			movedown();
		else if(my_strcmp(buf, KL) == 0)
			moveleft();
		else if(my_strcmp(buf, KR) == 0)
			moveright();
		else if(my_strcmp(buf, " ") == 0)
			doselect();
		else if(my_strcmp(buf, gl_env.esc) == 0)
			getout(0);
		else if(my_strcmp(buf, "\n") == 0)
			getout(1);
	}
	return 0;
}
