/*Bradford Smith (bsmith8)
*term_standout.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: enables highlight
*/
void term_standout()
{
	tputs(gl_env.standout, 1, my_termprint);
}
