/*Bradford Smith (bsmith8)
*client.c gtk project
*11/15/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "mygtksockets.h"

/*pre: takes in an int argc and a char **argv
*post: runs the client application with argc number of command line arguments
*	given by argv
*/
int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	init_main_win();
	gtk_main();
	return 0;
}
