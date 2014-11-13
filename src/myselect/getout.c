/*Bradford Smith (bsmith8)
*getout.c termcaps project
*11/10/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: takes in a char flag that is either 0 (ESC pressed) or 1 (Enter pressed)
*post: exits the program and prints the selected elements if flag is 1
*/
void getout(char flag)
{
	int i;

	#ifdef DEBUG
		my_str("getting out\n");
	#endif
	term_ve();
	term_clear();
	restore_terminal();
	if(flag)
	{
		for(i = 0; i < gl_env.nbelems; i++)
			if(gl_env.elements[i].mode)
			{
				my_str(gl_env.elements[i].elem);
				my_char(' ');
			}
	}
	exit(0);
}
