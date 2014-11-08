/*Bradford Smith (bsmith8)
*doselect.c termcaps project
*11/7/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: selects the current element
*/
void doselect()
{
	if(!gl_env.element[pos].mode)
		gl_env.element[pos].mode = 1;
	else
		gl_env.element[pos].mode = 0;
	refreshin();
}
