/*Bradford Smith (bsmith8)
*moveright.c termcaps project
*11/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: moves the cursor right one column
*	moves the cursor to the last element if there is no column to the right
*/
void moveright()
{
	refreshout(gl_env.pos);
	if((gl_env.pos += gl_env.win.ws_row) >= gl_env.nbelems)
		gl_env.pos = gl_env.nbelems - 1;
	refreshin();
}
