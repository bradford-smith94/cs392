/*Bradford Smith (bsmith8)
*term_vi.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: disables cursor display
*/
void term_vi()
{
	tputs(gl_env.cursoroff, 1, my_termprint);
}
