/*Bradford Smith (bsmith8)
*get_win_size.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: gets the window size and updates the global stuct
*/
char get_win_size()
{
	return ioctl(0, TIOGETWSZ, &gl_env.win);
}
