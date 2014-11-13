/*Bradford Smith (bsmith8)
*restore_terminal.c termcaps project
*11/9/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: restores the terminal and the stdio to their normal state
*/
void restore_terminal()
{
	ioctl(0, TCSETA, &gl_env.line_backup);
	dup2(gl_env.stdio_backup, 1);
}
