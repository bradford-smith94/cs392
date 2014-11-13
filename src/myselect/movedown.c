/*Bradford Smith (bsmith8)
*movedown.c termcaps project
*11/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: moves the cursor down one element
*	moves the cursor to the first element if already at the last element
*/
void movedown()
{
	refreshout(gl_env.pos);
	gl_env.pos++;
	if(gl_env.pos >= gl_env.nbelems)
		gl_env.pos %= gl_env.nbelems;
	refreshin();
}
