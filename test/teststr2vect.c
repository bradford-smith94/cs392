/*Bradford Smith (bsmith8)
*teststr2vect.c myminishell project test
*10/11/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "my.h"

/*pre: takes in int argc and char **argv
*post: runs the test program for my_str2vect
*	with argc number of command line arguments defined by argv
*/
int main(int argc, char **argv)
{
	int i;
	char *s;
	char **v;

	s = my_vect2str(&argv[1]);
	v = my_str2vect(s);
	for(i = 0; i < argc - 1; i++)
	{
		my_str(v[i]);
		my_str("<\\n\n");
	}
	return 0;
}
