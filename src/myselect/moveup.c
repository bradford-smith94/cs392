/*Bradford Smith (bsmith8)
*moveup.c termcaps project
*11/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: moves the cursor up one element
*	moves the cursor to the last element if it is at the first
*/
void moveup()
{
	refreshout(gl_env.pos);
	if(--gl_env.pos < 0)
		gl_env.pos = gl_env.nbelems - 1;
	refreshin();
}
