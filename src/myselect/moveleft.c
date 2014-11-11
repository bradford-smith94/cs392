/*Bradford Smith (bsmith8)
*moveleft.c termcaps project
*11/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: moves the cursor one column to the left
*	moves the cursor to the first element if there is no column to the left
*/
void moveleft()
{
	refreshout(gl_env.pos);
	if((gl_env.pos -= gl_env.win.ws_row) < 0)
		gl_env.pos = 0;
	refreshin();
}
