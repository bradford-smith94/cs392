/*Bradford Smith (bsmith8)
*term_ve.c termcaps project
*11/8/2014
*"I pledge my honor that I have abided by the Stevens Honor System."
*/

#include "myselect.h"

/*pre: none
*post: enables cursor display
*/
void term_ve()
{
	tputs(gl_env.cursoron, 1, my_termprint);
}
