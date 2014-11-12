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
	char buf[256];
	int n;

	if(argc < 2)
	{
		my_str("usage: ./myselect files [more files]...\n");
		exit(-1);
	}
	signal(SIGWINCH, show_elems);
	init_caps();
	init_terminal();
	setup_elems(argc, argv);
	show_elems();
	enterflg = 0;
	while(1)
	{
		if((n = read(0, buf, 255)) < 0)
		{
			my_str("ERROR: cannot read from keyboard\n");
			if(enterflg)
				enterflg = 0;
			break;
		}
		buf[n - 1] = '\0';
		if(my_strcmp(buf, gl_env.up) == 0)
			moveup();
		else if(my_strcmp(buf, gl_env.down) == 0)
			movedown();
		else if(my_strcmp(buf, gl_env.left) == 0)
			moveleft();
		else if(my_strcmp(buf, gl_env.right) == 0)
			moveright();
		else if(my_strcmp(buf, gl_env.esc) == 0)
			break;
		else if(my_strcmp(buf, "") == 0)
		{
			/*only a single \n was read (enter pressed)*/
			enterflg = 1;
			break;
		}
	}
	restore_terminal();
	getout(enterflg);
	return 0;
}
