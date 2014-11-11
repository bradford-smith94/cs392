/*Bradford Smith (bsmith8)
*setup_elems.c termcaps project
*11/10/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: takes in an int argc and a char **argv, argc is >= 2
*post: sets up the elements in the global struct from the command-line arguments
*/
void setup_elems(int argc, char **argv)
{
	int i;

	gl_env.elements = (t_elem*)xmalloc((argc - 1)*sizeof(t_elem));
	argv++;
	gl_env.nbelems = argc - 1;
	for(i = 0; i < argc - 1; i++)
	{
		gl_env.elements[i].elem = argv[i];
		gl_env.elements[i].size = my_strlen(argv[i]);
		gl_env.elements[i].x = 0;
		gl_env.elements[i].y = 0;
		gl_env.elements[i].mode = 0;
	}
}
